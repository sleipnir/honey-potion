#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "DiskMonitor.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct DiskMonitor_bpf* skel, uint time, bool all);
void choose_output(struct DiskMonitor_bpf* skel, bool all);
void output_opt(struct DiskMonitor_bpf* skel);
void output_all(struct DiskMonitor_bpf* skel);

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

  struct DiskMonitor_bpf *skel;
  int err;

  skel = DiskMonitor_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = DiskMonitor_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    DiskMonitor_bpf__destroy(skel);
    return -err;
  }


  err = DiskMonitor_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  DiskMonitor_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct DiskMonitor_bpf* skel, uint time, bool all){
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

void choose_output(struct DiskMonitor_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct DiskMonitor_bpf* skel){    int maxPoints = 3;
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

void output_all(struct DiskMonitor_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name alert_flag */
  struct bpf_map* alert_flag = skel->maps.alert_flag;
  int alert_flag_fd = bpf_map__fd(alert_flag);
  printf("alert_flag:\n");
  key = 0;
  int alert_flag_prev_key = 0;
  success = bpf_map_get_next_key(alert_flag_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(alert_flag_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    alert_flag_prev_key = key;
    success = bpf_map_get_next_key(alert_flag_fd, &alert_flag_prev_key, &key);
  }
  /* Printing map of name write_count */
  struct bpf_map* write_count = skel->maps.write_count;
  int write_count_fd = bpf_map__fd(write_count);
  printf("write_count:\n");
  key = 0;
  int write_count_prev_key = 0;
  success = bpf_map_get_next_key(write_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(write_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    write_count_prev_key = key;
    success = bpf_map_get_next_key(write_count_fd, &write_count_prev_key, &key);
  }
  /* Printing map of name read_count */
  struct bpf_map* read_count = skel->maps.read_count;
  int read_count_fd = bpf_map__fd(read_count);
  printf("read_count:\n");
  key = 0;
  int read_count_prev_key = 0;
  success = bpf_map_get_next_key(read_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(read_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    read_count_prev_key = key;
    success = bpf_map_get_next_key(read_count_fd, &read_count_prev_key, &key);
  }
  }
