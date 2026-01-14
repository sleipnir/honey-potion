// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} brk_count SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} munmap_count SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} mmap_count SEC(".maps");

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:641
typedef struct syscalls_enter_args
{
  /**
   * This is the tracepoint arguments.
   * Defined at: /sys/kernel/debug/tracing/events/raw_syscalls/sys_enter/format
   */
    unsigned short common_type;
    unsigned char common_flags;
    unsigned char common_preempt_count;
    int common_pid;
    long id;
    unsigned long args[6];
} syscalls_enter_args;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:685
char LICENSE[] SEC("license") = "Dual BSD/GPL";


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:719
SEC("tracepoint/raw_syscalls/sys_enter")
int main_func(syscalls_enter_args *ctx_arg) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:483
StrFormatSpec str_param1;
StrFormatSpec str_param2;
StrFormatSpec str_param3;

OpResult op_result = (OpResult){0};

int zero = 0;
char(*string_pool)[STRING_POOL_SIZE] = bpf_map_lookup_elem(&string_pool_map, &zero);
if (!string_pool)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access string pool, main function)."};
  goto CATCH;
}

unsigned *string_pool_index = bpf_map_lookup_elem(&string_pool_index_map, &zero);
if (!string_pool_index)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access string pool index, main function)."};
  goto CATCH;
}
*string_pool_index = 0;

__builtin_memcpy(*string_pool, "nil", 3);
__builtin_memcpy(*string_pool + 3, "false", 5);
__builtin_memcpy(*string_pool + 3 + 5, "true", 4);

Generic(*heap)[HEAP_SIZE] = bpf_map_lookup_elem(&heap_map, &zero);
if (!heap)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access heap map, main function)."};
  goto CATCH;
}

unsigned *heap_index = bpf_map_lookup_elem(&heap_index_map, &zero);
if (!heap_index)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access heap map index, main function)."};
  goto CATCH;
}
*heap_index = 0;

unsigned (*tuple_pool)[TUPLE_POOL_SIZE] = bpf_map_lookup_elem(&tuple_pool_map, &zero);
if (!tuple_pool)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access string pool, main function)."};
  goto CATCH;
}

unsigned *tuple_pool_index = bpf_map_lookup_elem(&tuple_pool_index_map, &zero);
if (!tuple_pool_index)
{
  op_result = (OpResult){.exception = 1, .exception_msg = "(UnexpectedBehavior) something wrong happened inside the Elixir runtime for eBPF. (can't access string pool index, main function)."};
  goto CATCH;
}
*tuple_pool_index = 0;

  // =============== beginning of user code ===============
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_2466 = ctx_arg->id;


op_result.exception = 0;
int syscall_id_1_ = helper_var_2466;

label_2434:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:445
int helper_var_2530 = bpf_get_current_pid_tgid();


op_result.exception = 0;
int pid_2_ = helper_var_2530;

label_2498:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_2562 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2594 = 9;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_2626;
if (syscall_id_1_ == helper_var_2594){
  helper_var_2626 = ATOM_TRUE;
} else {
  helper_var_2626 = ATOM_FALSE;
}


  if (to_bool(&helper_var_2626)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_2722 = bpf_map_lookup_elem(&mmap_count, &(pid_2_));
int helper_var_2690;
if(!helper_var_2722) {
  int helper_var_2754 = 0;
  helper_var_2690 = helper_var_2754;

} else {
  helper_var_2690 = helper_var_2722->value.integer;
}


op_result.exception = 0;
int count_3_ = helper_var_2690;

label_2658:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2786 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2818 = count_3_ + helper_var_2786;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2850 = {0};
 helper_var_2850.type = INTEGER; helper_var_2850.value.integer = helper_var_2818;

helper_var_2850.value.integer = helper_var_2818;
int helper_var_2882 = bpf_map_update_elem(&mmap_count, &(pid_2_), &helper_var_2850, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2914 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2946 = count_3_ + helper_var_2914;

bpf_printk("PID: %d; MMap Operations: %llu;", pid_2_, helper_var_2946);
int helper_var_2978 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3010 = {0};
 helper_var_3010.type = INTEGER; helper_var_3010.value.integer = helper_var_2978;

  helper_var_2562 = helper_var_3010;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3042 = 11;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_3074;
if (syscall_id_1_ == helper_var_3042){
  helper_var_3074 = ATOM_TRUE;
} else {
  helper_var_3074 = ATOM_FALSE;
}


  if (to_bool(&helper_var_3074)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3170 = bpf_map_lookup_elem(&munmap_count, &(pid_2_));
int helper_var_3138;
if(!helper_var_3170) {
  int helper_var_3202 = 0;
  helper_var_3138 = helper_var_3202;

} else {
  helper_var_3138 = helper_var_3170->value.integer;
}


op_result.exception = 0;
int count_4_ = helper_var_3138;

label_3106:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3234 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3266 = count_4_ + helper_var_3234;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3298 = {0};
 helper_var_3298.type = INTEGER; helper_var_3298.value.integer = helper_var_3266;

helper_var_3298.value.integer = helper_var_3266;
int helper_var_3330 = bpf_map_update_elem(&munmap_count, &(pid_2_), &helper_var_3298, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3362 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3394 = count_4_ + helper_var_3362;

bpf_printk("PID: %d; Munmap Operations: %llu;", pid_2_, helper_var_3394);
int helper_var_3426 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3458 = {0};
 helper_var_3458.type = INTEGER; helper_var_3458.value.integer = helper_var_3426;

  helper_var_2562 = helper_var_3458;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3490 = 12;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_3522;
if (syscall_id_1_ == helper_var_3490){
  helper_var_3522 = ATOM_TRUE;
} else {
  helper_var_3522 = ATOM_FALSE;
}


  if (to_bool(&helper_var_3522)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3618 = bpf_map_lookup_elem(&brk_count, &(pid_2_));
int helper_var_3586;
if(!helper_var_3618) {
  int helper_var_3650 = 0;
  helper_var_3586 = helper_var_3650;

} else {
  helper_var_3586 = helper_var_3618->value.integer;
}


op_result.exception = 0;
int count_5_ = helper_var_3586;

label_3554:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3682 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3714 = count_5_ + helper_var_3682;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3746 = {0};
 helper_var_3746.type = INTEGER; helper_var_3746.value.integer = helper_var_3714;

helper_var_3746.value.integer = helper_var_3714;
int helper_var_3778 = bpf_map_update_elem(&brk_count, &(pid_2_), &helper_var_3746, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3810 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3842 = count_5_ + helper_var_3810;

bpf_printk("PID: %d; Brk Operations: %llu;", pid_2_, helper_var_3842);
int helper_var_3874 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3906 = {0};
 helper_var_3906.type = INTEGER; helper_var_3906.value.integer = helper_var_3874;

  helper_var_2562 = helper_var_3906;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_3938 = ATOM_TRUE;
  if (to_bool(&helper_var_3938)) {
  int helper_var_3970 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4002 = {0};
 helper_var_4002.type = INTEGER; helper_var_4002.value.integer = helper_var_3970;

  helper_var_2562 = helper_var_4002;
} else {
  helper_var_2562 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}

}

}


int helper_var_4034 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_4034;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
