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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:670

int helper_var_99 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_163 = {0};
 helper_var_163.type = INTEGER; helper_var_163.value.integer = helper_var_99;

int helper_var_131 = 2;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_195 = {0};
 helper_var_195.type = INTEGER; helper_var_195.value.integer = helper_var_131;

if(*heap_index < (HEAP_SIZE-0)) {
  (*heap)[(*heap_index)+0] = helper_var_163;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
if(*tuple_pool_index < (TUPLE_POOL_SIZE-0)) {
  (*tuple_pool)[(*tuple_pool_index)+0] = (*heap_index)+0;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
if(*heap_index < (HEAP_SIZE-1)) {
  (*heap)[(*heap_index)+1] = helper_var_195;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
if(*tuple_pool_index < (TUPLE_POOL_SIZE-1)) {
  (*tuple_pool)[(*tuple_pool_index)+1] = (*heap_index)+1;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create tuple, the tuple pool is full."};
  goto CATCH;
}
*heap_index += 2;
*tuple_pool_index += 2;

Generic helper_var_227 = {.type = TUPLE, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};


op_result.exception = 0;
Generic one_two_0_ = helper_var_227;

label_67:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:711
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:711
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:691
Generic helper_var_291 = {.type = LIST, .value.tuple = (Tuple){.start = -1, .end = -1}};
if((*heap_index) < HEAP_SIZE && (*heap_index) >= 0) {
  (*heap)[(*heap_index)] = helper_var_291;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
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

Generic helper_var_323 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = one_two_0_;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_323;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:988
int helper_var_355 = 3;// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_387 = {0};
 helper_var_387.type = INTEGER; helper_var_387.value.integer = helper_var_355;
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

Generic helper_var_419 = (Generic){.type = LIST, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_387;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);
if(*heap_index < HEAP_SIZE && *heap_index >= 0) {
  (*heap)[(*heap_index)] = helper_var_419;
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to allocate memory in the heap."};
  goto CATCH;
}
++(*heap_index);


op_result.exception = 0;
if(helper_var_419.type != LIST){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}
Generic helper_var_451;
if(helper_var_419.value.tuple.start < TUPLE_POOL_SIZE && helper_var_419.value.tuple.start >= 0) {
  unsigned helper_var_483 = *((*tuple_pool)+(helper_var_419.value.tuple.start));
  if(helper_var_483 < HEAP_SIZE && helper_var_483 >= 0) {
    helper_var_451 = *(*(heap)+(helper_var_483));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_259;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1037
Generic label_515;
if(helper_var_419.value.tuple.start+1 < TUPLE_POOL_SIZE && helper_var_419.value.tuple.start+1 >= 0) {
  unsigned helper_var_547 = *((*tuple_pool)+(helper_var_419.value.tuple.start+1));
  if(helper_var_547 < HEAP_SIZE && helper_var_547 >= 0) {
    label_515 = *(*(heap)+(helper_var_547));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_259;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}
Generic helper_var_579;
if(label_515.value.tuple.start < TUPLE_POOL_SIZE && label_515.value.tuple.start >= 0) {
  unsigned helper_var_611 = *((*tuple_pool)+(label_515.value.tuple.start));
  if(helper_var_611 < HEAP_SIZE && helper_var_611 >= 0) {
    helper_var_579 = *(*(heap)+(helper_var_611));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_259;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}
Generic any_tuple_2_ = helper_var_579;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1037
Generic label_643;
if(label_515.value.tuple.start+1 < TUPLE_POOL_SIZE && label_515.value.tuple.start+1 >= 0) {
  unsigned helper_var_675 = *((*tuple_pool)+(label_515.value.tuple.start+1));
  if(helper_var_675 < HEAP_SIZE && helper_var_675 >= 0) {
    label_643 = *(*(heap)+(helper_var_675));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_259;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}
if(label_643.value.tuple.start != -1 || label_643.value.tuple.end != -1) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_259;
}

label_259:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797


op_result.exception = 0;
if(any_tuple_2_.type != TUPLE){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_707;
}
Generic helper_var_739;
if(any_tuple_2_.value.tuple.start + 0 < TUPLE_POOL_SIZE && any_tuple_2_.value.tuple.start + 0>= 0) {
  unsigned helper_var_771 = *((*tuple_pool)+(any_tuple_2_.value.tuple.start + 0));
  if(helper_var_771 < HEAP_SIZE && helper_var_771 >= 0) {
    helper_var_739 = *(*(heap)+(helper_var_771));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_707;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_707;
}
Generic x_3_ = helper_var_739;
Generic helper_var_803;
if(any_tuple_2_.value.tuple.start + 1 < TUPLE_POOL_SIZE && any_tuple_2_.value.tuple.start + 1>= 0) {
  unsigned helper_var_835 = *((*tuple_pool)+(any_tuple_2_.value.tuple.start + 1));
  if(helper_var_835 < HEAP_SIZE && helper_var_835 >= 0) {
    helper_var_803 = *(*(heap)+(helper_var_835));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_707;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_707;
}
int helper_var_867 = helper_var_803.value.integer;

label_707:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("x: %d", x_3_.value.integer);
int helper_var_899 = 0;


  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_899;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
