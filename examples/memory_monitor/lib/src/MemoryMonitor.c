#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "MemoryMonitor.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct MemoryMonitor_bpf* skel, uint time, bool all);
void choose_output(struct MemoryMonitor_bpf* skel, bool all);
void output_opt(struct MemoryMonitor_bpf* skel);
void output_all(struct MemoryMonitor_bpf* skel);

int main(int argc, char **argv) {

  bool printAll = false; // Prints only print:true otherwise
  uint lifeTime = 0; // If 0 -> infinite.

  int opt;
  while((opt = getopt(argc, argv, "pt:")) != -1){
    switch(opt){
      case 'p': printAll = true; break;
      case 't': lifeTime = atoi(optarg);
    }
  }

  struct MemoryMonitor_bpf *skel;
  int err;

  skel = MemoryMonitor_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = MemoryMonitor_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    MemoryMonitor_bpf__destroy(skel);
    return -err;
  }


  err = MemoryMonitor_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  MemoryMonitor_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct MemoryMonitor_bpf* skel, uint time, bool all){
  if(time == 0){
    while(1){
      choose_output(skel, all);
      sleep(1);
    }
  } else {
    time++;
    while(1){
      choose_output(skel, all);
      if(!--time) break;
      sleep(1);
    }
  }
}

void choose_output(struct MemoryMonitor_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct MemoryMonitor_bpf* skel){    int maxPoints = 3;
    int points = 0;
    while(1) {
        fflush(0);

        printf("eBPF program loaded and executing");
        for (int i = 0; i < (maxPoints + 1); i++) printf((i < points)? ".": " ");

        points = (points + 1) % (maxPoints + 1);
        printf("\r");

        sleep(1);
    }
}

void output_all(struct MemoryMonitor_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name brk_count */
  struct bpf_map* brk_count = skel->maps.brk_count;
  int brk_count_fd = bpf_map__fd(brk_count);
  printf("brk_count:\n");
  key = 0;
  int brk_count_prev_key = 0;
  success = bpf_map_get_next_key(brk_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(brk_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    brk_count_prev_key = key;
    success = bpf_map_get_next_key(brk_count_fd, &brk_count_prev_key, &key);
  }
  /* Printing map of name munmap_count */
  struct bpf_map* munmap_count = skel->maps.munmap_count;
  int munmap_count_fd = bpf_map__fd(munmap_count);
  printf("munmap_count:\n");
  key = 0;
  int munmap_count_prev_key = 0;
  success = bpf_map_get_next_key(munmap_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(munmap_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    munmap_count_prev_key = key;
    success = bpf_map_get_next_key(munmap_count_fd, &munmap_count_prev_key, &key);
  }
  /* Printing map of name mmap_count */
  struct bpf_map* mmap_count = skel->maps.mmap_count;
  int mmap_count_fd = bpf_map__fd(mmap_count);
  printf("mmap_count:\n");
  key = 0;
  int mmap_count_prev_key = 0;
  success = bpf_map_get_next_key(mmap_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(mmap_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    mmap_count_prev_key = key;
    success = bpf_map_get_next_key(mmap_count_fd, &mmap_count_prev_key, &key);
  }
  }
