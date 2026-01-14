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
} recv_count SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_HASH);__uint(max_entries, 4096);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} send_count SEC(".maps");

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
int helper_var_1191 = bpf_get_current_pid_tgid();


op_result.exception = 0;
int pid_1_ = helper_var_1191;

label_1159:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_1255 = ctx_arg->id;


op_result.exception = 0;
int syscall_id_2_ = helper_var_1255;

label_1223:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_1287 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1319 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_1351;
if (pid_1_ == helper_var_1319){
  helper_var_1351 = ATOM_TRUE;
} else {
  helper_var_1351 = ATOM_FALSE;
}


  if (to_bool(&helper_var_1351)) {
  int helper_var_1383 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1415 = {0};
 helper_var_1415.type = INTEGER; helper_var_1415.value.integer = helper_var_1383;

  helper_var_1287 = helper_var_1415;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1447 = 44;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_1479;
if (syscall_id_2_ == helper_var_1447){
  helper_var_1479 = ATOM_TRUE;
} else {
  helper_var_1479 = ATOM_FALSE;
}


  if (to_bool(&helper_var_1479)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1575 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_1543;
if(!helper_var_1575) {
  int helper_var_1607 = 0;
  helper_var_1543 = helper_var_1607;

} else {
  helper_var_1543 = helper_var_1575->value.integer;
}


op_result.exception = 0;
int count_3_ = helper_var_1543;

label_1511:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1671 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1703 = count_3_ + helper_var_1671;


op_result.exception = 0;
int new_count_4_ = helper_var_1703;

label_1639:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1735 = {0};
 helper_var_1735.type = INTEGER; helper_var_1735.value.integer = new_count_4_;

helper_var_1735.value.integer = new_count_4_;
int helper_var_1767 = bpf_map_update_elem(&send_count, &(pid_1_), &helper_var_1735, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1863 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_1831;
if(!helper_var_1863) {
  int helper_var_1895 = 0;
  helper_var_1831 = helper_var_1895;

} else {
  helper_var_1831 = helper_var_1863->value.integer;
}


op_result.exception = 0;
int recv_total_5_ = helper_var_1831;

label_1799:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1959 = new_count_4_ + recv_total_5_;


op_result.exception = 0;
int total_calls_6_ = helper_var_1959;

label_1927:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_1991 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2023 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2055 = total_calls_6_ > helper_var_2023;

  if (helper_var_2055) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_2087 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2119 = {0};
 helper_var_2119.type = INTEGER; helper_var_2119.value.integer = helper_var_2087;

helper_var_2119.value.integer = helper_var_2087;
int helper_var_2151 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_2119, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_6_);
int helper_var_2183 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2215 = {0};
 helper_var_2215.type = INTEGER; helper_var_2215.value.integer = helper_var_2183;

  helper_var_1991 = helper_var_2215;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_2247 = ATOM_TRUE;
  if (to_bool(&helper_var_2247)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_2279 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2311 = {0};
 helper_var_2311.type = INTEGER; helper_var_2311.value.integer = helper_var_2279;

helper_var_2311.value.integer = helper_var_2279;
int helper_var_2343 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_2311, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2375 = {0};
 helper_var_2375.type = INTEGER; helper_var_2375.value.integer = helper_var_2343;

  helper_var_1991 = helper_var_2375;
} else {
  helper_var_1991 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; sendto: %llu;", pid_1_, new_count_4_);
int helper_var_2407 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2439 = {0};
 helper_var_2439.type = INTEGER; helper_var_2439.value.integer = helper_var_2407;

  helper_var_1287 = helper_var_2439;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2471 = 46;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_2503;
if (syscall_id_2_ == helper_var_2471){
  helper_var_2503 = ATOM_TRUE;
} else {
  helper_var_2503 = ATOM_FALSE;
}


  if (to_bool(&helper_var_2503)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_2599 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_2567;
if(!helper_var_2599) {
  int helper_var_2631 = 0;
  helper_var_2567 = helper_var_2631;

} else {
  helper_var_2567 = helper_var_2599->value.integer;
}


op_result.exception = 0;
int count_7_ = helper_var_2567;

label_2535:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_2695 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2727 = count_7_ + helper_var_2695;


op_result.exception = 0;
int new_count_8_ = helper_var_2727;

label_2663:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_2759 = {0};
 helper_var_2759.type = INTEGER; helper_var_2759.value.integer = new_count_8_;

helper_var_2759.value.integer = new_count_8_;
int helper_var_2791 = bpf_map_update_elem(&send_count, &(pid_1_), &helper_var_2759, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_2887 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_2855;
if(!helper_var_2887) {
  int helper_var_2919 = 0;
  helper_var_2855 = helper_var_2919;

} else {
  helper_var_2855 = helper_var_2887->value.integer;
}


op_result.exception = 0;
int recv_total_9_ = helper_var_2855;

label_2823:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_2983 = new_count_8_ + recv_total_9_;


op_result.exception = 0;
int total_calls_10_ = helper_var_2983;

label_2951:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_3015 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3047 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3079 = total_calls_10_ > helper_var_3047;

  if (helper_var_3079) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_3111 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3143 = {0};
 helper_var_3143.type = INTEGER; helper_var_3143.value.integer = helper_var_3111;

helper_var_3143.value.integer = helper_var_3111;
int helper_var_3175 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_3143, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_10_);
int helper_var_3207 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3239 = {0};
 helper_var_3239.type = INTEGER; helper_var_3239.value.integer = helper_var_3207;

  helper_var_3015 = helper_var_3239;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_3271 = ATOM_TRUE;
  if (to_bool(&helper_var_3271)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_3303 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3335 = {0};
 helper_var_3335.type = INTEGER; helper_var_3335.value.integer = helper_var_3303;

helper_var_3335.value.integer = helper_var_3303;
int helper_var_3367 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_3335, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3399 = {0};
 helper_var_3399.type = INTEGER; helper_var_3399.value.integer = helper_var_3367;

  helper_var_3015 = helper_var_3399;
} else {
  helper_var_3015 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; sendmsg: %llu;", pid_1_, new_count_8_);
int helper_var_3431 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3463 = {0};
 helper_var_3463.type = INTEGER; helper_var_3463.value.integer = helper_var_3431;

  helper_var_1287 = helper_var_3463;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3495 = 307;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_3527;
if (syscall_id_2_ == helper_var_3495){
  helper_var_3527 = ATOM_TRUE;
} else {
  helper_var_3527 = ATOM_FALSE;
}


  if (to_bool(&helper_var_3527)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3623 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_3591;
if(!helper_var_3623) {
  int helper_var_3655 = 0;
  helper_var_3591 = helper_var_3655;

} else {
  helper_var_3591 = helper_var_3623->value.integer;
}


op_result.exception = 0;
int count_11_ = helper_var_3591;

label_3559:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3719 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3751 = count_11_ + helper_var_3719;


op_result.exception = 0;
int new_count_12_ = helper_var_3751;

label_3687:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3783 = {0};
 helper_var_3783.type = INTEGER; helper_var_3783.value.integer = new_count_12_;

helper_var_3783.value.integer = new_count_12_;
int helper_var_3815 = bpf_map_update_elem(&send_count, &(pid_1_), &helper_var_3783, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_3911 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_3879;
if(!helper_var_3911) {
  int helper_var_3943 = 0;
  helper_var_3879 = helper_var_3943;

} else {
  helper_var_3879 = helper_var_3911->value.integer;
}


op_result.exception = 0;
int recv_total_13_ = helper_var_3879;

label_3847:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4007 = new_count_12_ + recv_total_13_;


op_result.exception = 0;
int total_calls_14_ = helper_var_4007;

label_3975:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_4039 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4071 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4103 = total_calls_14_ > helper_var_4071;

  if (helper_var_4103) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_4135 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4167 = {0};
 helper_var_4167.type = INTEGER; helper_var_4167.value.integer = helper_var_4135;

helper_var_4167.value.integer = helper_var_4135;
int helper_var_4199 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_4167, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_14_);
int helper_var_4231 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4263 = {0};
 helper_var_4263.type = INTEGER; helper_var_4263.value.integer = helper_var_4231;

  helper_var_4039 = helper_var_4263;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_4295 = ATOM_TRUE;
  if (to_bool(&helper_var_4295)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_4327 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4359 = {0};
 helper_var_4359.type = INTEGER; helper_var_4359.value.integer = helper_var_4327;

helper_var_4359.value.integer = helper_var_4327;
int helper_var_4391 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_4359, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4423 = {0};
 helper_var_4423.type = INTEGER; helper_var_4423.value.integer = helper_var_4391;

  helper_var_4039 = helper_var_4423;
} else {
  helper_var_4039 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; sendmmsg: %llu;", pid_1_, new_count_12_);
int helper_var_4455 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4487 = {0};
 helper_var_4487.type = INTEGER; helper_var_4487.value.integer = helper_var_4455;

  helper_var_1287 = helper_var_4487;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4519 = 45;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_4551;
if (syscall_id_2_ == helper_var_4519){
  helper_var_4551 = ATOM_TRUE;
} else {
  helper_var_4551 = ATOM_FALSE;
}


  if (to_bool(&helper_var_4551)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_4647 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_4615;
if(!helper_var_4647) {
  int helper_var_4679 = 0;
  helper_var_4615 = helper_var_4679;

} else {
  helper_var_4615 = helper_var_4647->value.integer;
}


op_result.exception = 0;
int count_15_ = helper_var_4615;

label_4583:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4743 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4775 = count_15_ + helper_var_4743;


op_result.exception = 0;
int new_count_16_ = helper_var_4775;

label_4711:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4807 = {0};
 helper_var_4807.type = INTEGER; helper_var_4807.value.integer = new_count_16_;

helper_var_4807.value.integer = new_count_16_;
int helper_var_4839 = bpf_map_update_elem(&recv_count, &(pid_1_), &helper_var_4807, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_4935 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_4903;
if(!helper_var_4935) {
  int helper_var_4967 = 0;
  helper_var_4903 = helper_var_4967;

} else {
  helper_var_4903 = helper_var_4935->value.integer;
}


op_result.exception = 0;
int send_total_17_ = helper_var_4903;

label_4871:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_5031 = send_total_17_ + new_count_16_;


op_result.exception = 0;
int total_calls_18_ = helper_var_5031;

label_4999:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_5063 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5095 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_5127 = total_calls_18_ > helper_var_5095;

  if (helper_var_5127) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_5159 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5191 = {0};
 helper_var_5191.type = INTEGER; helper_var_5191.value.integer = helper_var_5159;

helper_var_5191.value.integer = helper_var_5159;
int helper_var_5223 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_5191, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_18_);
int helper_var_5255 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5287 = {0};
 helper_var_5287.type = INTEGER; helper_var_5287.value.integer = helper_var_5255;

  helper_var_5063 = helper_var_5287;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_5319 = ATOM_TRUE;
  if (to_bool(&helper_var_5319)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_5351 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5383 = {0};
 helper_var_5383.type = INTEGER; helper_var_5383.value.integer = helper_var_5351;

helper_var_5383.value.integer = helper_var_5351;
int helper_var_5415 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_5383, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5447 = {0};
 helper_var_5447.type = INTEGER; helper_var_5447.value.integer = helper_var_5415;

  helper_var_5063 = helper_var_5447;
} else {
  helper_var_5063 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; recvfrom: %llu;", pid_1_, new_count_16_);
int helper_var_5479 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5511 = {0};
 helper_var_5511.type = INTEGER; helper_var_5511.value.integer = helper_var_5479;

  helper_var_1287 = helper_var_5511;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5543 = 47;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_5575;
if (syscall_id_2_ == helper_var_5543){
  helper_var_5575 = ATOM_TRUE;
} else {
  helper_var_5575 = ATOM_FALSE;
}


  if (to_bool(&helper_var_5575)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_5671 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_5639;
if(!helper_var_5671) {
  int helper_var_5703 = 0;
  helper_var_5639 = helper_var_5703;

} else {
  helper_var_5639 = helper_var_5671->value.integer;
}


op_result.exception = 0;
int count_19_ = helper_var_5639;

label_5607:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_5767 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_5799 = count_19_ + helper_var_5767;


op_result.exception = 0;
int new_count_20_ = helper_var_5799;

label_5735:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_5831 = {0};
 helper_var_5831.type = INTEGER; helper_var_5831.value.integer = new_count_20_;

helper_var_5831.value.integer = new_count_20_;
int helper_var_5863 = bpf_map_update_elem(&recv_count, &(pid_1_), &helper_var_5831, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_5959 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_5927;
if(!helper_var_5959) {
  int helper_var_5991 = 0;
  helper_var_5927 = helper_var_5991;

} else {
  helper_var_5927 = helper_var_5959->value.integer;
}


op_result.exception = 0;
int send_total_21_ = helper_var_5927;

label_5895:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6055 = send_total_21_ + new_count_20_;


op_result.exception = 0;
int total_calls_22_ = helper_var_6055;

label_6023:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_6087 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_6119 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6151 = total_calls_22_ > helper_var_6119;

  if (helper_var_6151) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_6183 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6215 = {0};
 helper_var_6215.type = INTEGER; helper_var_6215.value.integer = helper_var_6183;

helper_var_6215.value.integer = helper_var_6183;
int helper_var_6247 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_6215, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_22_);
int helper_var_6279 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6311 = {0};
 helper_var_6311.type = INTEGER; helper_var_6311.value.integer = helper_var_6279;

  helper_var_6087 = helper_var_6311;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_6343 = ATOM_TRUE;
  if (to_bool(&helper_var_6343)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_6375 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6407 = {0};
 helper_var_6407.type = INTEGER; helper_var_6407.value.integer = helper_var_6375;

helper_var_6407.value.integer = helper_var_6375;
int helper_var_6439 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_6407, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6471 = {0};
 helper_var_6471.type = INTEGER; helper_var_6471.value.integer = helper_var_6439;

  helper_var_6087 = helper_var_6471;
} else {
  helper_var_6087 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; recvmsg: %llu;", pid_1_, new_count_20_);
int helper_var_6503 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6535 = {0};
 helper_var_6535.type = INTEGER; helper_var_6535.value.integer = helper_var_6503;

  helper_var_1287 = helper_var_6535;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_6567 = 299;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_6599;
if (syscall_id_2_ == helper_var_6567){
  helper_var_6599 = ATOM_TRUE;
} else {
  helper_var_6599 = ATOM_FALSE;
}


  if (to_bool(&helper_var_6599)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_6695 = bpf_map_lookup_elem(&recv_count, &(pid_1_));
int helper_var_6663;
if(!helper_var_6695) {
  int helper_var_6727 = 0;
  helper_var_6663 = helper_var_6727;

} else {
  helper_var_6663 = helper_var_6695->value.integer;
}


op_result.exception = 0;
int count_23_ = helper_var_6663;

label_6631:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_6791 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_6823 = count_23_ + helper_var_6791;


op_result.exception = 0;
int new_count_24_ = helper_var_6823;

label_6759:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_6855 = {0};
 helper_var_6855.type = INTEGER; helper_var_6855.value.integer = new_count_24_;

helper_var_6855.value.integer = new_count_24_;
int helper_var_6887 = bpf_map_update_elem(&recv_count, &(pid_1_), &helper_var_6855, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_6983 = bpf_map_lookup_elem(&send_count, &(pid_1_));
int helper_var_6951;
if(!helper_var_6983) {
  int helper_var_7015 = 0;
  helper_var_6951 = helper_var_7015;

} else {
  helper_var_6951 = helper_var_6983->value.integer;
}


op_result.exception = 0;
int send_total_25_ = helper_var_6951;

label_6919:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_7079 = send_total_25_ + new_count_24_;


op_result.exception = 0;
int total_calls_26_ = helper_var_7079;

label_7047:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_7111 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_7143 = 50000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_7175 = total_calls_26_ > helper_var_7143;

  if (helper_var_7175) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_7207 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7239 = {0};
 helper_var_7239.type = INTEGER; helper_var_7239.value.integer = helper_var_7207;

helper_var_7239.value.integer = helper_var_7207;
int helper_var_7271 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_7239, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; alert total calls: %llu;", pid_1_, total_calls_26_);
int helper_var_7303 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7335 = {0};
 helper_var_7335.type = INTEGER; helper_var_7335.value.integer = helper_var_7303;

  helper_var_7111 = helper_var_7335;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_7367 = ATOM_TRUE;
  if (to_bool(&helper_var_7367)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

int helper_var_7399 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7431 = {0};
 helper_var_7431.type = INTEGER; helper_var_7431.value.integer = helper_var_7399;

helper_var_7431.value.integer = helper_var_7399;
int helper_var_7463 = bpf_map_update_elem(&alert_flag, &(pid_1_), &helper_var_7431, BPF_ANY);

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7495 = {0};
 helper_var_7495.type = INTEGER; helper_var_7495.value.integer = helper_var_7463;

  helper_var_7111 = helper_var_7495;
} else {
  helper_var_7111 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("PID: %llu; recvmmsg: %llu;", pid_1_, new_count_24_);
int helper_var_7527 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7559 = {0};
 helper_var_7559.type = INTEGER; helper_var_7559.value.integer = helper_var_7527;

  helper_var_1287 = helper_var_7559;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_7591 = ATOM_TRUE;
  if (to_bool(&helper_var_7591)) {
  int helper_var_7623 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_7655 = {0};
 helper_var_7655.type = INTEGER; helper_var_7655.value.integer = helper_var_7623;

  helper_var_1287 = helper_var_7655;
} else {
  helper_var_1287 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}

}

}

}

}

}

}


int helper_var_7687 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_7687;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
