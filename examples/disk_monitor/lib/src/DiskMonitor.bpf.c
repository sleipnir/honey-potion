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
} alert_flag SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} write_count SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} read_count SEC(".maps");

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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:445
int helper_var_455 = bpf_get_current_pid_tgid();


op_result.exception = 0;
int pid_1_ = helper_var_455;

label_423:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_519 = ctx_arg->id;


op_result.exception = 0;
int syscall_id_2_ = helper_var_519;

label_487:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_551 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_583 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_615;
if (pid_1_ == helper_var_583){
  helper_var_615 = ATOM_TRUE;
} else {
  helper_var_615 = ATOM_FALSE;
}


  if (to_bool(&helper_var_615)) {
  int helper_var_647 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_679 = {0};
 helper_var_679.type = INTEGER; helper_var_679.value.integer = helper_var_647;

  helper_var_551 = helper_var_679;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_711 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_743;
if (syscall_id_2_ == helper_var_711){
  helper_var_743 = ATOM_TRUE;
} else {
  helper_var_743 = ATOM_FALSE;
}


  if (to_bool(&helper_var_743)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_839 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_807;
if(!helper_var_839) {
  int helper_var_871 = 0;
  helper_var_807 = helper_var_871;

} else {
  helper_var_807 = helper_var_839->value.integer;
}


op_result.exception = 0;
int count_3_ = helper_var_807;

label_775:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_935 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_967 = count_3_ + helper_var_935;


op_result.exception = 0;
int new_count_4_ = helper_var_967;

label_903:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_999 = {0};
 helper_var_999.type = INTEGER; helper_var_999.value.integer = new_count_4_;

helper_var_999.value.integer = new_count_4_;
int helper_var_1031 = bpf_map_update_elem(&read_count, &(pid_1_), &helper_var_999, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1127 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_1095;
if(!helper_var_1127) {
  int helper_var_1159 = 0;
  helper_var_1095 = helper_var_1159;

} else {
  helper_var_1095 = helper_var_1127->value.integer;
}


op_result.exception = 0;
int write_total_5_ = helper_var_1095;

label_1063:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1223 = new_count_4_ + write_total_5_;


op_result.exception = 0;
int total_calls_6_ = helper_var_1223;

label_1191:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_1255 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1287 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1319 = total_calls_6_ > helper_var_1287;

  if (helper_var_1319) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_1351 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1383 = {0};
 helper_var_1383.type = INTEGER; helper_var_1383.value.integer = helper_var_1351;

helper_var_1383.value.integer = helper_var_1351;
int helper_var_1415 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_1383, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_6_);
int helper_var_1447 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1479 = {0};
 helper_var_1479.type = INTEGER; helper_var_1479.value.integer = helper_var_1447;

  helper_var_1255 = helper_var_1479;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_1511 = ATOM_TRUE;
  if (to_bool(&helper_var_1511)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_1543 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1575 = {0};
 helper_var_1575.type = INTEGER; helper_var_1575.value.integer = helper_var_1543;

helper_var_1575.value.integer = helper_var_1543;
int helper_var_1607 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_1575, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1639 = {0};
 helper_var_1639.type = INTEGER; helper_var_1639.value.integer = helper_var_1607;

  helper_var_1255 = helper_var_1639;
} else {
  helper_var_1255 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; read: %llu;", pid_1_, new_count_4_);
int helper_var_1671 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1703 = {0};
 helper_var_1703.type = INTEGER; helper_var_1703.value.integer = helper_var_1671;

  helper_var_551 = helper_var_1703;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1735 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_1767;
if (syscall_id_2_ == helper_var_1735){
  helper_var_1767 = ATOM_TRUE;
} else {
  helper_var_1767 = ATOM_FALSE;
}


  if (to_bool(&helper_var_1767)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1863 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_1831;
if(!helper_var_1863) {
  int helper_var_1895 = 0;
  helper_var_1831 = helper_var_1895;

} else {
  helper_var_1831 = helper_var_1863->value.integer;
}


op_result.exception = 0;
int count_7_ = helper_var_1831;

label_1799:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1959 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1991 = count_7_ + helper_var_1959;


op_result.exception = 0;
int new_count_8_ = helper_var_1991;

label_1927:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2023 = {0};
 helper_var_2023.type = INTEGER; helper_var_2023.value.integer = new_count_8_;

helper_var_2023.value.integer = new_count_8_;
int helper_var_2055 = bpf_map_update_elem(&write_count, &(pid_1_), &helper_var_2023, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_2151 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_2119;
if(!helper_var_2151) {
  int helper_var_2183 = 0;
  helper_var_2119 = helper_var_2183;

} else {
  helper_var_2119 = helper_var_2151->value.integer;
}


op_result.exception = 0;
int read_total_9_ = helper_var_2119;

label_2087:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2180 = read_total_9_ + new_count_8_;


op_result.exception = 0;
int total_calls_10_ = helper_var_2180;

label_2215:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_2212 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2244 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2276 = total_calls_10_ > helper_var_2244;

  if (helper_var_2276) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_2308 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2340 = {0};
 helper_var_2340.type = INTEGER; helper_var_2340.value.integer = helper_var_2308;

helper_var_2340.value.integer = helper_var_2308;
int helper_var_2372 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_2340, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_10_);
int helper_var_2404 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2436 = {0};
 helper_var_2436.type = INTEGER; helper_var_2436.value.integer = helper_var_2404;

  helper_var_2212 = helper_var_2436;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_2468 = ATOM_TRUE;
  if (to_bool(&helper_var_2468)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_2500 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2532 = {0};
 helper_var_2532.type = INTEGER; helper_var_2532.value.integer = helper_var_2500;

helper_var_2532.value.integer = helper_var_2500;
int helper_var_2564 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_2532, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2596 = {0};
 helper_var_2596.type = INTEGER; helper_var_2596.value.integer = helper_var_2564;

  helper_var_2212 = helper_var_2596;
} else {
  helper_var_2212 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; write: %llu;", pid_1_, new_count_8_);
int helper_var_2628 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2660 = {0};
 helper_var_2660.type = INTEGER; helper_var_2660.value.integer = helper_var_2628;

  helper_var_551 = helper_var_2660;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2692 = 17;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_2724;
if (syscall_id_2_ == helper_var_2692){
  helper_var_2724 = ATOM_TRUE;
} else {
  helper_var_2724 = ATOM_FALSE;
}


  if (to_bool(&helper_var_2724)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_2820 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_2788;
if(!helper_var_2820) {
  int helper_var_2852 = 0;
  helper_var_2788 = helper_var_2852;

} else {
  helper_var_2788 = helper_var_2820->value.integer;
}


op_result.exception = 0;
int count_11_ = helper_var_2788;

label_2756:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2916 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2948 = count_11_ + helper_var_2916;


op_result.exception = 0;
int new_count_12_ = helper_var_2948;

label_2884:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2980 = {0};
 helper_var_2980.type = INTEGER; helper_var_2980.value.integer = new_count_12_;

helper_var_2980.value.integer = new_count_12_;
int helper_var_3012 = bpf_map_update_elem(&read_count, &(pid_1_), &helper_var_2980, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3108 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_3076;
if(!helper_var_3108) {
  int helper_var_3140 = 0;
  helper_var_3076 = helper_var_3140;

} else {
  helper_var_3076 = helper_var_3108->value.integer;
}


op_result.exception = 0;
int write_total_13_ = helper_var_3076;

label_3044:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3204 = new_count_12_ + write_total_13_;


op_result.exception = 0;
int total_calls_14_ = helper_var_3204;

label_3172:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_3236 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3268 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3300 = total_calls_14_ > helper_var_3268;

  if (helper_var_3300) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_3332 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3364 = {0};
 helper_var_3364.type = INTEGER; helper_var_3364.value.integer = helper_var_3332;

helper_var_3364.value.integer = helper_var_3332;
int helper_var_3396 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_3364, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_14_);
int helper_var_3428 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3460 = {0};
 helper_var_3460.type = INTEGER; helper_var_3460.value.integer = helper_var_3428;

  helper_var_3236 = helper_var_3460;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_3492 = ATOM_TRUE;
  if (to_bool(&helper_var_3492)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_3524 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3556 = {0};
 helper_var_3556.type = INTEGER; helper_var_3556.value.integer = helper_var_3524;

helper_var_3556.value.integer = helper_var_3524;
int helper_var_3588 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_3556, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3620 = {0};
 helper_var_3620.type = INTEGER; helper_var_3620.value.integer = helper_var_3588;

  helper_var_3236 = helper_var_3620;
} else {
  helper_var_3236 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; pread64: %llu;", pid_1_, new_count_12_);
int helper_var_3652 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3684 = {0};
 helper_var_3684.type = INTEGER; helper_var_3684.value.integer = helper_var_3652;

  helper_var_551 = helper_var_3684;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3716 = 18;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_3748;
if (syscall_id_2_ == helper_var_3716){
  helper_var_3748 = ATOM_TRUE;
} else {
  helper_var_3748 = ATOM_FALSE;
}


  if (to_bool(&helper_var_3748)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3844 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_3812;
if(!helper_var_3844) {
  int helper_var_3876 = 0;
  helper_var_3812 = helper_var_3876;

} else {
  helper_var_3812 = helper_var_3844->value.integer;
}


op_result.exception = 0;
int count_15_ = helper_var_3812;

label_3780:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3940 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3972 = count_15_ + helper_var_3940;


op_result.exception = 0;
int new_count_16_ = helper_var_3972;

label_3908:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4004 = {0};
 helper_var_4004.type = INTEGER; helper_var_4004.value.integer = new_count_16_;

helper_var_4004.value.integer = new_count_16_;
int helper_var_4036 = bpf_map_update_elem(&write_count, &(pid_1_), &helper_var_4004, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_4132 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_4100;
if(!helper_var_4132) {
  int helper_var_4164 = 0;
  helper_var_4100 = helper_var_4164;

} else {
  helper_var_4100 = helper_var_4132->value.integer;
}


op_result.exception = 0;
int read_total_17_ = helper_var_4100;

label_4068:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4228 = read_total_17_ + new_count_16_;


op_result.exception = 0;
int total_calls_18_ = helper_var_4228;

label_4196:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_4260 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4292 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4324 = total_calls_18_ > helper_var_4292;

  if (helper_var_4324) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_4356 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4388 = {0};
 helper_var_4388.type = INTEGER; helper_var_4388.value.integer = helper_var_4356;

helper_var_4388.value.integer = helper_var_4356;
int helper_var_4420 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_4388, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_18_);
int helper_var_4452 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4484 = {0};
 helper_var_4484.type = INTEGER; helper_var_4484.value.integer = helper_var_4452;

  helper_var_4260 = helper_var_4484;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_4516 = ATOM_TRUE;
  if (to_bool(&helper_var_4516)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_4548 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4580 = {0};
 helper_var_4580.type = INTEGER; helper_var_4580.value.integer = helper_var_4548;

helper_var_4580.value.integer = helper_var_4548;
int helper_var_4612 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_4580, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4644 = {0};
 helper_var_4644.type = INTEGER; helper_var_4644.value.integer = helper_var_4612;

  helper_var_4260 = helper_var_4644;
} else {
  helper_var_4260 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; pwrite64: %llu;", pid_1_, new_count_16_);
int helper_var_4676 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4708 = {0};
 helper_var_4708.type = INTEGER; helper_var_4708.value.integer = helper_var_4676;

  helper_var_551 = helper_var_4708;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4740 = 19;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_4772;
if (syscall_id_2_ == helper_var_4740){
  helper_var_4772 = ATOM_TRUE;
} else {
  helper_var_4772 = ATOM_FALSE;
}


  if (to_bool(&helper_var_4772)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_4868 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_4836;
if(!helper_var_4868) {
  int helper_var_4900 = 0;
  helper_var_4836 = helper_var_4900;

} else {
  helper_var_4836 = helper_var_4868->value.integer;
}


op_result.exception = 0;
int count_19_ = helper_var_4836;

label_4804:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4964 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4996 = count_19_ + helper_var_4964;


op_result.exception = 0;
int new_count_20_ = helper_var_4996;

label_4932:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5028 = {0};
 helper_var_5028.type = INTEGER; helper_var_5028.value.integer = new_count_20_;

helper_var_5028.value.integer = new_count_20_;
int helper_var_5060 = bpf_map_update_elem(&read_count, &(pid_1_), &helper_var_5028, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_5156 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_5124;
if(!helper_var_5156) {
  int helper_var_5188 = 0;
  helper_var_5124 = helper_var_5188;

} else {
  helper_var_5124 = helper_var_5156->value.integer;
}


op_result.exception = 0;
int write_total_21_ = helper_var_5124;

label_5092:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_5252 = new_count_20_ + write_total_21_;


op_result.exception = 0;
int total_calls_22_ = helper_var_5252;

label_5220:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_5284 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5316 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_5348 = total_calls_22_ > helper_var_5316;

  if (helper_var_5348) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_5380 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5412 = {0};
 helper_var_5412.type = INTEGER; helper_var_5412.value.integer = helper_var_5380;

helper_var_5412.value.integer = helper_var_5380;
int helper_var_5444 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_5412, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_22_);
int helper_var_5476 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5508 = {0};
 helper_var_5508.type = INTEGER; helper_var_5508.value.integer = helper_var_5476;

  helper_var_5284 = helper_var_5508;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_5540 = ATOM_TRUE;
  if (to_bool(&helper_var_5540)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_5572 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5604 = {0};
 helper_var_5604.type = INTEGER; helper_var_5604.value.integer = helper_var_5572;

helper_var_5604.value.integer = helper_var_5572;
int helper_var_5636 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_5604, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5668 = {0};
 helper_var_5668.type = INTEGER; helper_var_5668.value.integer = helper_var_5636;

  helper_var_5284 = helper_var_5668;
} else {
  helper_var_5284 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; readv: %llu;", pid_1_, new_count_20_);
int helper_var_5700 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5732 = {0};
 helper_var_5732.type = INTEGER; helper_var_5732.value.integer = helper_var_5700;

  helper_var_551 = helper_var_5732;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5764 = 20;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_5796;
if (syscall_id_2_ == helper_var_5764){
  helper_var_5796 = ATOM_TRUE;
} else {
  helper_var_5796 = ATOM_FALSE;
}


  if (to_bool(&helper_var_5796)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_5892 = bpf_map_lookup_elem(&write_count, &(pid_1_));
int helper_var_5860;
if(!helper_var_5892) {
  int helper_var_5924 = 0;
  helper_var_5860 = helper_var_5924;

} else {
  helper_var_5860 = helper_var_5892->value.integer;
}


op_result.exception = 0;
int count_23_ = helper_var_5860;

label_5828:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5988 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6020 = count_23_ + helper_var_5988;


op_result.exception = 0;
int new_count_24_ = helper_var_6020;

label_5956:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6052 = {0};
 helper_var_6052.type = INTEGER; helper_var_6052.value.integer = new_count_24_;

helper_var_6052.value.integer = new_count_24_;
int helper_var_6084 = bpf_map_update_elem(&write_count, &(pid_1_), &helper_var_6052, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_6180 = bpf_map_lookup_elem(&read_count, &(pid_1_));
int helper_var_6148;
if(!helper_var_6180) {
  int helper_var_6212 = 0;
  helper_var_6148 = helper_var_6212;

} else {
  helper_var_6148 = helper_var_6180->value.integer;
}


op_result.exception = 0;
int read_total_25_ = helper_var_6148;

label_6116:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6276 = read_total_25_ + new_count_24_;


op_result.exception = 0;
int total_calls_26_ = helper_var_6276;

label_6244:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_6308 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_6340 = 10000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6372 = total_calls_26_ > helper_var_6340;

  if (helper_var_6372) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_6404 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6436 = {0};
 helper_var_6436.type = INTEGER; helper_var_6436.value.integer = helper_var_6404;

helper_var_6436.value.integer = helper_var_6404;
int helper_var_6468 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_6436, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total I/O calls: %llu;", pid_1_, total_calls_26_);
int helper_var_6500 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6532 = {0};
 helper_var_6532.type = INTEGER; helper_var_6532.value.integer = helper_var_6500;

  helper_var_6308 = helper_var_6532;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_6564 = ATOM_TRUE;
  if (to_bool(&helper_var_6564)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_6596 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6628 = {0};
 helper_var_6628.type = INTEGER; helper_var_6628.value.integer = helper_var_6596;

helper_var_6628.value.integer = helper_var_6596;
int helper_var_6660 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_6628, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6692 = {0};
 helper_var_6692.type = INTEGER; helper_var_6692.value.integer = helper_var_6660;

  helper_var_6308 = helper_var_6692;
} else {
  helper_var_6308 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; writev: %llu;", pid_1_, new_count_24_);
int helper_var_6724 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6756 = {0};
 helper_var_6756.type = INTEGER; helper_var_6756.value.integer = helper_var_6724;

  helper_var_551 = helper_var_6756;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_6788 = ATOM_TRUE;
  if (to_bool(&helper_var_6788)) {
  int helper_var_6820 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6852 = {0};
 helper_var_6852.type = INTEGER; helper_var_6852.value.integer = helper_var_6820;

  helper_var_551 = helper_var_6852;
} else {
  helper_var_551 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}

}

}

}

}

}

}


int helper_var_6884 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_6884;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
