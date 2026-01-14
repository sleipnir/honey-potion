// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>


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
int helper_var_2854 = 1;

op_result.exception = 0;

label_2822:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1379
unsigned len_helper_var_2950 = 4;
unsigned end_helper_var_2950 = *string_pool_index + len_helper_var_2950 - 1;
if(end_helper_var_2950 + 1 >= STRING_POOL_SIZE) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create string, the string pool is full."};
  goto CATCH;
}

if(*string_pool_index < STRING_POOL_SIZE - len_helper_var_2950) {
  __builtin_memcpy(&(*string_pool)[*string_pool_index], "foo", len_helper_var_2950);
}

String helper_var_2918 = (String){.start = *string_pool_index, .end = end_helper_var_2950};
*string_pool_index = end_helper_var_2950 + 1;


op_result.exception = 0;
if(helper_var_2918.start < STRING_POOL_SIZE - 0 && helper_var_2918.start >= 0) {
  if('f' != *((*string_pool)+(helper_var_2918.start + 0))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_2886;
  }
}
if(helper_var_2918.start < STRING_POOL_SIZE - 1 && helper_var_2918.start >= 0) {
  if('o' != *((*string_pool)+(helper_var_2918.start + 1))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_2886;
  }
}
if(helper_var_2918.start < STRING_POOL_SIZE - 2 && helper_var_2918.start >= 0) {
  if('o' != *((*string_pool)+(helper_var_2918.start + 2))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_2886;
  }
}

label_2886:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("Success");
int helper_var_2982 = 0;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1379
unsigned len_helper_var_3078 = 4;
unsigned end_helper_var_3078 = *string_pool_index + len_helper_var_3078 - 1;
if(end_helper_var_3078 + 1 >= STRING_POOL_SIZE) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create string, the string pool is full."};
  goto CATCH;
}

if(*string_pool_index < STRING_POOL_SIZE - len_helper_var_3078) {
  __builtin_memcpy(&(*string_pool)[*string_pool_index], "foo", len_helper_var_3078);
}

String helper_var_3046 = (String){.start = *string_pool_index, .end = end_helper_var_3078};
*string_pool_index = end_helper_var_3078 + 1;


op_result.exception = 0;
if(helper_var_3046.start < STRING_POOL_SIZE - 0 && helper_var_3046.start >= 0) {
  if('b' != *((*string_pool)+(helper_var_3046.start + 0))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3014;
  }
}
if(helper_var_3046.start < STRING_POOL_SIZE - 1 && helper_var_3046.start >= 0) {
  if('a' != *((*string_pool)+(helper_var_3046.start + 1))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3014;
  }
}
if(helper_var_3046.start < STRING_POOL_SIZE - 2 && helper_var_3046.start >= 0) {
  if('r' != *((*string_pool)+(helper_var_3046.start + 2))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3014;
  }
}

label_3014:
if(op_result.exception == 1) {
  goto CATCH;
}

int helper_var_3110 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_3110;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
