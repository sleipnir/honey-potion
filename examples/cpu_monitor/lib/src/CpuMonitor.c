#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "CpuMonitor.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct CpuMonitor_bpf* skel, uint time, bool all);
void choose_output(struct CpuMonitor_bpf* skel, bool all);
void output_opt(struct CpuMonitor_bpf* skel);
void output_all(struct CpuMonitor_bpf* skel);

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

  struct CpuMonitor_bpf *skel;
  int err;

  skel = CpuMonitor_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = CpuMonitor_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    CpuMonitor_bpf__destroy(skel);
    return -err;
  }


  err = CpuMonitor_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  CpuMonitor_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct CpuMonitor_bpf* skel, uint time, bool all){
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

void choose_output(struct CpuMonitor_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct CpuMonitor_bpf* skel){    int maxPoints = 3;
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

void output_all(struct CpuMonitor_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name total_time */
  struct bpf_map* total_time = skel->maps.total_time;
  int total_time_fd = bpf_map__fd(total_time);
  printf("total_time:\n");
  key = 0;
  int total_time_prev_key = 0;
  success = bpf_map_get_next_key(total_time_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(total_time_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    total_time_prev_key = key;
    success = bpf_map_get_next_key(total_time_fd, &total_time_prev_key, &key);
  }
  /* Printing map of name start_time */
  struct bpf_map* start_time = skel->maps.start_time;
  int start_time_fd = bpf_map__fd(start_time);
  printf("start_time:\n");
  key = 0;
  int start_time_prev_key = 0;
  success = bpf_map_get_next_key(start_time_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(start_time_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    start_time_prev_key = key;
    success = bpf_map_get_next_key(start_time_fd, &start_time_prev_key, &key);
  }
  }
