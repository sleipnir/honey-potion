#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "NetworkMonitor.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct NetworkMonitor_bpf* skel, uint time, bool all);
void choose_output(struct NetworkMonitor_bpf* skel, bool all);
void output_opt(struct NetworkMonitor_bpf* skel);
void output_all(struct NetworkMonitor_bpf* skel);

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

  struct NetworkMonitor_bpf *skel;
  int err;

  skel = NetworkMonitor_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = NetworkMonitor_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    NetworkMonitor_bpf__destroy(skel);
    return -err;
  }


  err = NetworkMonitor_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  NetworkMonitor_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct NetworkMonitor_bpf* skel, uint time, bool all){
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

void choose_output(struct NetworkMonitor_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct NetworkMonitor_bpf* skel){    int maxPoints = 3;
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

void output_all(struct NetworkMonitor_bpf* skel) {
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
  /* Printing map of name recv_count */
  struct bpf_map* recv_count = skel->maps.recv_count;
  int recv_count_fd = bpf_map__fd(recv_count);
  printf("recv_count:\n");
  key = 0;
  int recv_count_prev_key = 0;
  success = bpf_map_get_next_key(recv_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(recv_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    recv_count_prev_key = key;
    success = bpf_map_get_next_key(recv_count_fd, &recv_count_prev_key, &key);
  }
  /* Printing map of name send_count */
  struct bpf_map* send_count = skel->maps.send_count;
  int send_count_fd = bpf_map__fd(send_count);
  printf("send_count:\n");
  key = 0;
  int send_count_prev_key = 0;
  success = bpf_map_get_next_key(send_count_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(send_count_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    send_count_prev_key = key;
    success = bpf_map_get_next_key(send_count_fd, &send_count_prev_key, &key);
  }
  }
