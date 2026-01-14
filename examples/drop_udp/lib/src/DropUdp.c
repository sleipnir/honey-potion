#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "DropUdp.skel.h"

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
void output(struct DropUdp_bpf* skel, uint time, bool all);
void choose_output(struct DropUdp_bpf* skel, bool all);
void output_opt(struct DropUdp_bpf* skel);
void output_all(struct DropUdp_bpf* skel);

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

  struct DropUdp_bpf *skel;
  int err;

  skel = DropUdp_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  bpf_program__set_type(skel->progs.main_func, BPF_PROG_TYPE_XDP);


  err = DropUdp_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    DropUdp_bpf__destroy(skel);
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

void output(struct DropUdp_bpf* skel, uint time, bool all){
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

void choose_output(struct DropUdp_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct DropUdp_bpf* skel){    int maxPoints = 3;
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

void output_all(struct DropUdp_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  }
