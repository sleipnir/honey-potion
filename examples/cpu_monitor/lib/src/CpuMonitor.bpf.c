// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>

struct {
  __uint(type, BPF_MAP_TYPE_ARRAY);__uint(max_entries, 41943040);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} total_time SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_ARRAY);__uint(max_entries, 41943040);
  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} start_time SEC(".maps");

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:627
typedef struct sched_switch_args {
    __u64 pad;               // 8 bytes of padding to align tracepoint args
    char prev_comm[16];      // previous task name
    __u32 prev_pid;          // previous PID
    __u32 prev_prio;         // previous priority
    __u64 prev_state;        // state of the previous task
    char next_comm[16];      // next task name
    __u32 next_pid;          // next PID
    __u32 next_prio;         // next priority
}sched_switch_args;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:685
char LICENSE[] SEC("license") = "Dual BSD/GPL";


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:719
SEC("tracepoint/sched/sched_switch")
int main_func(struct sched_switch_args *ctx_arg) {
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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:200
int helper_var_647 = bpf_ktime_get_ns();


op_result.exception = 0;
int ts_1_ = helper_var_647;

label_615:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_711 = ctx_arg->prev_pid;


op_result.exception = 0;
int prev_pid_3_ = helper_var_711;

label_679:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_775 = ctx_arg->next_pid;


op_result.exception = 0;
int next_pid_4_ = helper_var_775;

label_743:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_807 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_839 = 41943040;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_871 = prev_pid_3_ > helper_var_839;

  if (helper_var_871) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191
int helper_var_903 = 0;
bpf_printk("PID: Out of Bounds; CPU Time (ns): %llu;", next_pid_4_, helper_var_903);
int helper_var_935 = 0;

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_967 = {0};
 helper_var_967.type = INTEGER; helper_var_967.value.integer = helper_var_935;

  helper_var_807 = helper_var_967;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_999 = ATOM_TRUE;
  if (to_bool(&helper_var_999)) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1095 = bpf_map_lookup_elem(&start_time, &(prev_pid_3_));
int helper_var_1063;
if(!helper_var_1095) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'start_time'."};
  goto CATCH;

} else {
  helper_var_1063 = helper_var_1095->value.integer;
}


op_result.exception = 0;
int start_5_ = helper_var_1063;

label_1031:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1159 = ts_1_ - start_5_;


op_result.exception = 0;
int delta_6_ = helper_var_1159;

label_1127:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299


Generic *helper_var_1255 = bpf_map_lookup_elem(&total_time, &(prev_pid_3_));
int helper_var_1223;
if(!helper_var_1255) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'total_time'."};
  goto CATCH;

} else {
  helper_var_1223 = helper_var_1255->value.integer;
}


op_result.exception = 0;
int total_7_ = helper_var_1223;

label_1191:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1287 = total_7_ + delta_6_;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1319 = {0};
 helper_var_1319.type = INTEGER; helper_var_1319.value.integer = helper_var_1287;

helper_var_1319.value.integer = helper_var_1287;
int helper_var_1351 = bpf_map_update_elem(&total_time, &(prev_pid_3_), &helper_var_1319, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1383 = {0};
 helper_var_1383.type = INTEGER; helper_var_1383.value.integer = ts_1_;

helper_var_1383.value.integer = ts_1_;
int helper_var_1415 = bpf_map_update_elem(&start_time, &(next_pid_4_), &helper_var_1383, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_1447 = total_7_ + delta_6_;

bpf_printk("PID: %d; CPU Time (ns): %llu;", next_pid_4_, helper_var_1447);
int helper_var_1479 = 0;


  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1511 = {0};
 helper_var_1511.type = INTEGER; helper_var_1511.value.integer = helper_var_1479;

  helper_var_807 = helper_var_1511;
} else {
  helper_var_807 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}


int helper_var_1543 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_1543;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
