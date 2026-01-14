#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "ForceKill.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct ForceKill_bpf* skel, uint time, bool all);
void choose_output(struct ForceKill_bpf* skel, bool all);
void output_opt(struct ForceKill_bpf* skel);
void output_all(struct ForceKill_bpf* skel);

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

  struct ForceKill_bpf *skel;
  int err;

  skel = ForceKill_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = ForceKill_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    ForceKill_bpf__destroy(skel);
    return -err;
  }


  err = ForceKill_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  ForceKill_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct ForceKill_bpf* skel, uint time, bool all){
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

void choose_output(struct ForceKill_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct ForceKill_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name ForceKills */
  struct bpf_map* ForceKills = skel->maps.ForceKills;
  int ForceKills_fd = bpf_map__fd(ForceKills);
  printf("ForceKills:\n");
  key = 0;
  int ForceKills_prev_key = 0;
  success = bpf_map_get_next_key(ForceKills_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(ForceKills_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    ForceKills_prev_key = key;
    success = bpf_map_get_next_key(ForceKills_fd, &ForceKills_prev_key, &key);
  }
}

void output_all(struct ForceKill_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name ForceKills */
  struct bpf_map* ForceKills = skel->maps.ForceKills;
  int ForceKills_fd = bpf_map__fd(ForceKills);
  printf("ForceKills:\n");
  key = 0;
  int ForceKills_prev_key = 0;
  success = bpf_map_get_next_key(ForceKills_fd, NULL, &key);
  while(success == 0){
    success = bpf_map_lookup_elem(ForceKills_fd, &key, &value);
    if (success == 0) {
      printf("Entry %d: %ld\n", key, value.value.integer);

    }
    ForceKills_prev_key = key;
    success = bpf_map_get_next_key(ForceKills_fd, &ForceKills_prev_key, &key);
  }
  }
