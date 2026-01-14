#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <stdio.h>
#include <unistd.h>
#include <runtime_generic.bpf.h>
#include "CountSyscalls.skel.h"

// xdp_md includes
#include <net/if.h>
#include <linux/if_link.h>
#include <signal.h>
void output(struct CountSyscalls_bpf* skel, uint time, bool all);
void choose_output(struct CountSyscalls_bpf* skel, bool all);
void output_opt(struct CountSyscalls_bpf* skel);
void output_all(struct CountSyscalls_bpf* skel);

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

  struct CountSyscalls_bpf *skel;
  int err;

  skel = CountSyscalls_bpf__open();
  if(!skel){
    fprintf(stderr, "Skeleton failed opening.\n");
    return 1;
  }

  

  err = CountSyscalls_bpf__load(skel);
  if(err){
    fprintf(stderr, "Failed loading or verification of BPF skeleton.\n");
    CountSyscalls_bpf__destroy(skel);
    return -err;
  }


  err = CountSyscalls_bpf__attach(skel);
if(err){
  fprintf(stderr, "Failed attaching BPF skeleton.\n");
  CountSyscalls_bpf__destroy(skel);
  return -err;
}


  output(skel, lifeTime, printAll);
}

void output(struct CountSyscalls_bpf* skel, uint time, bool all){
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

void choose_output(struct CountSyscalls_bpf* skel, bool all){
  if(all) output_all(skel);
  else output_opt(skel);
}

void output_opt(struct CountSyscalls_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name Count_Sys_Calls_Invoked */
  struct bpf_map* Count_Sys_Calls_Invoked = skel->maps.Count_Sys_Calls_Invoked;
  int Count_Sys_Calls_Invoked_fd = bpf_map__fd(Count_Sys_Calls_Invoked);
  printf("Count_Sys_Calls_Invoked:\n");
    key = 0;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "Syscall: enter_read (0) | Qtt:", 0);
    }
    key = 1;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "Syscall: enter_write (1) | Qtt:", 1);
    }
    key = 62;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_kill (62) | Qtt:", 62);
    }
    key = 83;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_mkdir (83) | Qtt:", 83);
    }
    key = 318;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_getrandom (318) | Qtt:", 318);
    }

}

void output_all(struct CountSyscalls_bpf* skel) {
  int key;
  unsigned char chkey[6];
  int success;
  Generic value = (Generic){0};

  printf("\e[1;1H\e[2J");

  /* Printing map of name Count_Sys_Calls_Invoked */
  struct bpf_map* Count_Sys_Calls_Invoked = skel->maps.Count_Sys_Calls_Invoked;
  int Count_Sys_Calls_Invoked_fd = bpf_map__fd(Count_Sys_Calls_Invoked);
  printf("Count_Sys_Calls_Invoked:\n");
    key = 0;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "Syscall: enter_read (0) | Qtt:", 0);
    }
    key = 1;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "Syscall: enter_write (1) | Qtt:", 1);
    }
    key = 62;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_kill (62) | Qtt:", 62);
    }
    key = 83;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_mkdir (83) | Qtt:", 83);
    }
    key = 318;
    success = bpf_map_lookup_elem(Count_Sys_Calls_Invoked_fd, &key, &value);
    if(success == 0){
      printf("Entry %d: %ld\n", key, value.value.integer);

    } else {
      printf("Element %s failed to print with key %d.\n", "SysCall: enter_getrandom (318) | Qtt:", 318);
    }

  }
