#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "TrafficCounter.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
static __u32 XDPFLAGS = XDP_FLAGS_SKB_MODE;
static int IFINDEX;
void _unloadProg() {
    bpf_xdp_attach(IFINDEX, -1, XDPFLAGS, NULL);
    printf("Unloading the eBPF program...");
    exit(0);
}
void output(struct TrafficCounter_bpf* skel, uint time, bool all);
void choose_output(struct TrafficCounter_bpf* skel, bool all);
void output_opt(struct TrafficCounter_bpf* skel);
void output_all(struct TrafficCounter_bpf* skel);

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

  struct TrafficCounter_bpf *skel;
  int err;

  skel = TrafficCounter_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  bpf_program__set_type(skel->progs.main_func, BPF_PROG_TYPE_XDP);


  err = TrafficCounter_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    TrafficCounter_bpf__destroy(skel);
    return -err;
  }


  signal(SIGINT, _unloadProg);
signal(SIGTERM , _unloadProg);

int prog_fd = bpf_program__fd(skel->progs.main_func);

IFINDEX = if_nametoindex("lo");
if(bpf_xdp_attach(IFINDEX, prog_fd, XDPFLAGS, NULL) < 0){
  printf("Failed to link set xdp_fd.");
  return -1;
}


  output(skel, lifeTime, printAll);
}

void output(struct TrafficCounter_bpf* skel, uint time, bool all){
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

void choose_output(struct TrafficCounter_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct TrafficCounter_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name TrafficCount */
  struct bpf_map* TrafficCount = skel->maps.TrafficCount;
  int TrafficCount_fd = bpf_map__fd(TrafficCount);
  printf("TrafficCount:\n");
  key = 0;
  unsigned char TrafficCount_prev_key[6];
  success = bpf_map_get_next_key(TrafficCount_fd, NULL, chkey);
  while(success == 0){
    success = bpf_map_lookup_elem(TrafficCount_fd, chkey, &value);
    if (success == 0) {
        printf("Entry %02x:%02x:%02x:%02x:%02x:%02x: %ld\n",
    chkey[0], chkey[1], chkey[2], chkey[3], chkey[4], chkey[5], value.value.integer
  );

    }
    memcpy(TrafficCount_prev_key, chkey, 6);
    success = bpf_map_get_next_key(TrafficCount_fd, TrafficCount_prev_key, chkey);
  }
}

void output_all(struct TrafficCounter_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name TrafficCount */
  struct bpf_map* TrafficCount = skel->maps.TrafficCount;
  int TrafficCount_fd = bpf_map__fd(TrafficCount);
  printf("TrafficCount:\n");
  key = 0;
  unsigned char TrafficCount_prev_key[6];
  success = bpf_map_get_next_key(TrafficCount_fd, NULL, chkey);
  while(success == 0){
    success = bpf_map_lookup_elem(TrafficCount_fd, chkey, &value);
    if (success == 0) {
        printf("Entry %02x:%02x:%02x:%02x:%02x:%02x: %ld\n",
    chkey[0], chkey[1], chkey[2], chkey[3], chkey[4], chkey[5], value.value.integer
  );

    }
    memcpy(TrafficCount_prev_key, chkey, 6);
    success = bpf_map_get_next_key(TrafficCount_fd, TrafficCount_prev_key, chkey);
  }
  }
