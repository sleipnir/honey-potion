// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>

struct {
  __uint(type, BPF_MAP_TYPE_ARRAY);__uint(max_entries, 5);


  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} Second_Example_map SEC(".maps");

struct {
  __uint(type, BPF_MAP_TYPE_ARRAY);__uint(max_entries, 7);

  __uint(key_size, sizeof(int));
  __uint(value_size, sizeof(Generic));
} Example_map SEC(".maps");

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:658
typedef struct syscalls_enter_write_args
{
  /**
   * This is the tracepoint arguments.
   * Defined at: /sys/kernel/debug/tracing/events/syscalls/sys_enter_write/format
   */
   unsigned short common_type;
   unsigned char common_flags;
   unsigned char common_preempt_count;
   int common_pid;
   int __syscall_nr;
   unsigned int fd;
   const char * buf;
   size_t count;
} syscalls_enter_write_args;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:685
char LICENSE[] SEC("license") = "Dual BSD/GPL";


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:719
SEC("tracepoint/syscalls/sys_enter_write")
int main_func(syscalls_enter_write_args *ctx_arg) {
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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_2568 = 0;

Generic *helper_var_2600 = bpf_map_lookup_elem(&Example_map, &(helper_var_2568));
int helper_var_2536;
if(!helper_var_2600) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_2536 = helper_var_2600->value.integer;
}


op_result.exception = 0;
int entry_0_1_ = helper_var_2536;

label_2504:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_2696 = 1;

Generic *helper_var_2728 = bpf_map_lookup_elem(&Example_map, &(helper_var_2696));
int helper_var_2664;
if(!helper_var_2728) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_2664 = helper_var_2728->value.integer;
}


op_result.exception = 0;
int entry_1_2_ = helper_var_2664;

label_2632:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_2824 = 2;

Generic *helper_var_2856 = bpf_map_lookup_elem(&Example_map, &(helper_var_2824));
int helper_var_2792;
if(!helper_var_2856) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_2792 = helper_var_2856->value.integer;
}


op_result.exception = 0;
int entry_2_3_ = helper_var_2792;

label_2760:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_2952 = 3;

Generic *helper_var_2984 = bpf_map_lookup_elem(&Example_map, &(helper_var_2952));
int helper_var_2920;
if(!helper_var_2984) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_2920 = helper_var_2984->value.integer;
}


op_result.exception = 0;
int entry_3_4_ = helper_var_2920;

label_2888:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_3080 = 4;

Generic *helper_var_3112 = bpf_map_lookup_elem(&Example_map, &(helper_var_3080));
int helper_var_3048;
if(!helper_var_3112) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_3048 = helper_var_3112->value.integer;
}


op_result.exception = 0;
int entry_4_5_ = helper_var_3048;

label_3016:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_3208 = 5;

Generic *helper_var_3240 = bpf_map_lookup_elem(&Example_map, &(helper_var_3208));
int helper_var_3176;
if(!helper_var_3240) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_3176 = helper_var_3240->value.integer;
}


op_result.exception = 0;
int entry_5_6_ = helper_var_3176;

label_3144:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_3336 = 6;

Generic *helper_var_3368 = bpf_map_lookup_elem(&Example_map, &(helper_var_3336));
int helper_var_3304;
if(!helper_var_3368) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Example_map'."};
  goto CATCH;

} else {
  helper_var_3304 = helper_var_3368->value.integer;
}


op_result.exception = 0;
int entry_6_7_ = helper_var_3304;

label_3272:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:299
int helper_var_3464 = 0;

Generic *helper_var_3496 = bpf_map_lookup_elem(&Second_Example_map, &(helper_var_3464));
int helper_var_3432;
if(!helper_var_3496) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(KeyNotFound) The key provided was not found in the map 'Second_Example_map'."};
  goto CATCH;

} else {
  helper_var_3432 = helper_var_3496->value.integer;
}


op_result.exception = 0;
int entry_7_8_ = helper_var_3432;

label_3400:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_3528 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3560 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3592 = entry_0_1_ + helper_var_3560;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3624 = {0};
 helper_var_3624.type = INTEGER; helper_var_3624.value.integer = helper_var_3592;

helper_var_3624.value.integer = helper_var_3592;
int helper_var_3656 = bpf_map_update_elem(&Example_map, &(helper_var_3528), &helper_var_3624, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_3688 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3720 = 2;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3752 = entry_1_2_ + helper_var_3720;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3784 = {0};
 helper_var_3784.type = INTEGER; helper_var_3784.value.integer = helper_var_3752;

helper_var_3784.value.integer = helper_var_3752;
int helper_var_3816 = bpf_map_update_elem(&Example_map, &(helper_var_3688), &helper_var_3784, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_3848 = 2;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_3880 = 3;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_3912 = entry_2_3_ + helper_var_3880;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3944 = {0};
 helper_var_3944.type = INTEGER; helper_var_3944.value.integer = helper_var_3912;

helper_var_3944.value.integer = helper_var_3912;
int helper_var_3976 = bpf_map_update_elem(&Example_map, &(helper_var_3848), &helper_var_3944, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_4008 = 3;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4040 = 4;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4072 = entry_3_4_ + helper_var_4040;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4104 = {0};
 helper_var_4104.type = INTEGER; helper_var_4104.value.integer = helper_var_4072;

helper_var_4104.value.integer = helper_var_4072;
int helper_var_4136 = bpf_map_update_elem(&Example_map, &(helper_var_4008), &helper_var_4104, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_4168 = 4;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4200 = 5;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4232 = entry_4_5_ + helper_var_4200;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4264 = {0};
 helper_var_4264.type = INTEGER; helper_var_4264.value.integer = helper_var_4232;

helper_var_4264.value.integer = helper_var_4232;
int helper_var_4296 = bpf_map_update_elem(&Example_map, &(helper_var_4168), &helper_var_4264, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_4328 = 5;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4360 = 6;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4392 = entry_5_6_ + helper_var_4360;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4424 = {0};
 helper_var_4424.type = INTEGER; helper_var_4424.value.integer = helper_var_4392;

helper_var_4424.value.integer = helper_var_4392;
int helper_var_4456 = bpf_map_update_elem(&Example_map, &(helper_var_4328), &helper_var_4424, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_4488 = 6;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4520 = 7;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4552 = entry_6_7_ + helper_var_4520;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4584 = {0};
 helper_var_4584.type = INTEGER; helper_var_4584.value.integer = helper_var_4552;

helper_var_4584.value.integer = helper_var_4552;
int helper_var_4616 = bpf_map_update_elem(&Example_map, &(helper_var_4488), &helper_var_4584, BPF_ANY);

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:434
int helper_var_4648 = 0;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_4680 = 8;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_4712 = entry_7_8_ + helper_var_4680;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_4744 = {0};
 helper_var_4744.type = INTEGER; helper_var_4744.value.integer = helper_var_4712;

helper_var_4744.value.integer = helper_var_4712;
int helper_var_4776 = bpf_map_update_elem(&Second_Example_map, &(helper_var_4648), &helper_var_4744, BPF_ANY);

int helper_var_4808 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_4808;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
