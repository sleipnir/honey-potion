// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:611
typedef struct syscalls_enter_kill_args
{
  /**
  * This is the tracepoint arguments of the kill functions.
  * Defined at: /sys/kernel/debug/tracing/events/syscalls/sys_enter_kill/format
  */
  long long pad;

  long syscall_nr;
  long pid;
  long sig;
} syscalls_enter_kill_args;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:685
char LICENSE[] SEC("license") = "Dual BSD/GPL";


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:719
SEC("tracepoint/syscalls/sys_enter_kill")
int main_func(syscalls_enter_kill_args *ctx_arg) {
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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:711
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:711
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:691
Generic helper_var_2887 = {.type = LIST, .value.tuple = (Tuple){.start = -1, .end = -1}};
if((*heap_index) < HEAP_SIZE && (*heap_index) >= 0) {
  (*heap)[(*heap_index)] = helper_var_2887;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
Generic helper_var_2919 = ATOM_NIL;if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index);
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index)-1;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);

Generic helper_var_2951 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_2919;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_2951;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
int helper_var_2983 = 1;// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3015 = {0};
 helper_var_3015.type = INTEGER; helper_var_3015.value.integer = helper_var_2983;
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index);
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index)-1;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);

Generic helper_var_3047 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3015;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3047;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);


op_result.exception = 0;
Generic t_0_ = helper_var_3047;

label_2855:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:701
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
int helper_var_3111 = 2;// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3143 = {0};
 helper_var_3143.type = INTEGER; helper_var_3143.value.integer = helper_var_3111;
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index);
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index)-1;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);

Generic helper_var_3175 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3143;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3175;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);


op_result.exception = 0;
Generic t_1_ = helper_var_3175;

label_3079:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:701
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
int helper_var_3239 = 3;// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_3271 = {0};
 helper_var_3271.type = INTEGER; helper_var_3271.value.integer = helper_var_3239;
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index);
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);
if(*tuple_pool_index < TUPLE_POOL_SIZE && *tuple_pool_index >= 0) {
  (*tuple_pool)[(*tuple_pool_index)] = (*heap_index)-1;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
++(*tuple_pool_index);

Generic helper_var_3303 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3271;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_3303;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);


op_result.exception = 0;
Generic t_2_ = helper_var_3303;

label_3207:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797


op_result.exception = 0;
if(t_2_.type != LIST){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3335;
}
Generic helper_var_3367;
if(t_2_.value.tuple.start < TUPLE_POOL_SIZE && t_2_.value.tuple.start >= 0) {
  unsigned helper_var_3399 = *((*tuple_pool)+(t_2_.value.tuple.start));
  if(helper_var_3399 < HEAP_SIZE && helper_var_3399 >= 0) {
    helper_var_3367 = *(*(heap)+(helper_var_3399));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3335;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3335;
}
Generic _three_3_ = helper_var_3367;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1037
Generic label_3431;
if(t_2_.value.tuple.start+1 < TUPLE_POOL_SIZE && t_2_.value.tuple.start+1 >= 0) {
  unsigned helper_var_3463 = *((*tuple_pool)+(t_2_.value.tuple.start+1));
  if(helper_var_3463 < HEAP_SIZE && helper_var_3463 >= 0) {
    label_3431 = *(*(heap)+(helper_var_3463));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3335;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3335;
}
Generic a_4_ = label_3431;

label_3335:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797


op_result.exception = 0;
if(a_4_.type != LIST){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3495;
}
Generic helper_var_3527;
if(a_4_.value.tuple.start < TUPLE_POOL_SIZE && a_4_.value.tuple.start >= 0) {
  unsigned helper_var_3559 = *((*tuple_pool)+(a_4_.value.tuple.start));
  if(helper_var_3559 < HEAP_SIZE && helper_var_3559 >= 0) {
    helper_var_3527 = *(*(heap)+(helper_var_3559));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3495;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3495;
}
Generic two_5_ = helper_var_3527;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1037
Generic label_3591;
if(a_4_.value.tuple.start+1 < TUPLE_POOL_SIZE && a_4_.value.tuple.start+1 >= 0) {
  unsigned helper_var_3623 = *((*tuple_pool)+(a_4_.value.tuple.start+1));
  if(helper_var_3623 < HEAP_SIZE && helper_var_3623 >= 0) {
    label_3591 = *(*(heap)+(helper_var_3623));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_3495;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_3495;
}
Generic _a_6_ = label_3591;

label_3495:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("%d", two_5_.value.integer);
int helper_var_3655 = 0;

int helper_var_3687 = 0;

  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_3687;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
