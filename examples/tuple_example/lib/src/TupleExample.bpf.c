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

int helper_var_1092 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1412 = {0};
 helper_var_1412.type = INTEGER; helper_var_1412.value.integer = helper_var_1092;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:670

int helper_var_1124 = 2;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1348 = {0};
 helper_var_1348.type = INTEGER; helper_var_1348.value.integer = helper_var_1124;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:670

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1379
unsigned len_helper_var_1188 = 12;
unsigned end_helper_var_1188 = *string_pool_index + len_helper_var_1188 - 1;
if(end_helper_var_1188 + 1 >= STRING_POOL_SIZE) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MemoryLimitReached) Impossible to create string, the string pool is full."};
  goto CATCH;
}

if(*string_pool_index < STRING_POOL_SIZE - len_helper_var_1188) {
  __builtin_memcpy(&(*string_pool)[*string_pool_index], "some string", len_helper_var_1188);
}

String helper_var_1156 = (String){.start = *string_pool_index, .end = end_helper_var_1188};
*string_pool_index = end_helper_var_1188 + 1;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
  Generic helper_var_1252 = {0};
  helper_var_1252.type = STRING; helper_var_1252.value.string = helper_var_1156;

int helper_var_1220 = 4;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1284 = {0};
 helper_var_1284.type = INTEGER; helper_var_1284.value.integer = helper_var_1220;

if(*heap_index < (HEAP_SIZE-0)) {
  (*heap)[(*heap_index)+0] = helper_var_1252;
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
  (*heap)[(*heap_index)+1] = helper_var_1284;
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

Generic helper_var_1316 = {.type = TUPLE, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};


if(*heap_index < (HEAP_SIZE-0)) {
  (*heap)[(*heap_index)+0] = helper_var_1348;
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
  (*heap)[(*heap_index)+1] = helper_var_1316;
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

Generic helper_var_1380 = {.type = TUPLE, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};


if(*heap_index < (HEAP_SIZE-0)) {
  (*heap)[(*heap_index)+0] = helper_var_1412;
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
  (*heap)[(*heap_index)+1] = helper_var_1380;
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

Generic helper_var_1444 = {.type = TUPLE, .value.tuple = (Tuple){.start = (*tuple_pool_index)-2, .end = (*tuple_pool_index)-1}};


op_result.exception = 0;
if(helper_var_1444.type != TUPLE){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_1060;
}
Generic helper_var_1476;
if(helper_var_1444.value.tuple.start + 0 < TUPLE_POOL_SIZE && helper_var_1444.value.tuple.start + 0>= 0) {
  unsigned helper_var_1508 = *((*tuple_pool)+(helper_var_1444.value.tuple.start + 0));
  if(helper_var_1508 < HEAP_SIZE && helper_var_1508 >= 0) {
    helper_var_1476 = *(*(heap)+(helper_var_1508));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
if(helper_var_1476.type != INTEGER || 1 != helper_var_1476.value.integer) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_1060;
}
Generic helper_var_1540;
if(helper_var_1444.value.tuple.start + 1 < TUPLE_POOL_SIZE && helper_var_1444.value.tuple.start + 1>= 0) {
  unsigned helper_var_1572 = *((*tuple_pool)+(helper_var_1444.value.tuple.start + 1));
  if(helper_var_1572 < HEAP_SIZE && helper_var_1572 >= 0) {
    helper_var_1540 = *(*(heap)+(helper_var_1572));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
if(helper_var_1540.type != TUPLE){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_1060;
}
Generic helper_var_1604;
if(helper_var_1540.value.tuple.start + 0 < TUPLE_POOL_SIZE && helper_var_1540.value.tuple.start + 0>= 0) {
  unsigned helper_var_1636 = *((*tuple_pool)+(helper_var_1540.value.tuple.start + 0));
  if(helper_var_1636 < HEAP_SIZE && helper_var_1636 >= 0) {
    helper_var_1604 = *(*(heap)+(helper_var_1636));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
if(helper_var_1604.type != INTEGER || 2 != helper_var_1604.value.integer) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_1060;
}
Generic helper_var_1668;
if(helper_var_1540.value.tuple.start + 1 < TUPLE_POOL_SIZE && helper_var_1540.value.tuple.start + 1>= 0) {
  unsigned helper_var_1700 = *((*tuple_pool)+(helper_var_1540.value.tuple.start + 1));
  if(helper_var_1700 < HEAP_SIZE && helper_var_1700 >= 0) {
    helper_var_1668 = *(*(heap)+(helper_var_1700));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
if(helper_var_1668.type != TUPLE){
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_1060;
}
Generic helper_var_1732;
if(helper_var_1668.value.tuple.start + 0 < TUPLE_POOL_SIZE && helper_var_1668.value.tuple.start + 0>= 0) {
  unsigned helper_var_1764 = *((*tuple_pool)+(helper_var_1668.value.tuple.start + 0));
  if(helper_var_1764 < HEAP_SIZE && helper_var_1764 >= 0) {
    helper_var_1732 = *(*(heap)+(helper_var_1764));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
  if(helper_var_1732.type != STRING) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }

  String helper_var_1796 = helper_var_1732.value.string;
  if(11 != (helper_var_1796.end - helper_var_1796.start)){
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
if(helper_var_1796.start < STRING_POOL_SIZE - 0 && helper_var_1796.start >= 0) {
  if('s' != *((*string_pool)+(helper_var_1796.start + 0))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 1 && helper_var_1796.start >= 0) {
  if('o' != *((*string_pool)+(helper_var_1796.start + 1))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 2 && helper_var_1796.start >= 0) {
  if('m' != *((*string_pool)+(helper_var_1796.start + 2))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 3 && helper_var_1796.start >= 0) {
  if('e' != *((*string_pool)+(helper_var_1796.start + 3))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 4 && helper_var_1796.start >= 0) {
  if(' ' != *((*string_pool)+(helper_var_1796.start + 4))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 5 && helper_var_1796.start >= 0) {
  if('s' != *((*string_pool)+(helper_var_1796.start + 5))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 6 && helper_var_1796.start >= 0) {
  if('t' != *((*string_pool)+(helper_var_1796.start + 6))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 7 && helper_var_1796.start >= 0) {
  if('r' != *((*string_pool)+(helper_var_1796.start + 7))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 8 && helper_var_1796.start >= 0) {
  if('i' != *((*string_pool)+(helper_var_1796.start + 8))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 9 && helper_var_1796.start >= 0) {
  if('n' != *((*string_pool)+(helper_var_1796.start + 9))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
if(helper_var_1796.start < STRING_POOL_SIZE - 10 && helper_var_1796.start >= 0) {
  if('g' != *((*string_pool)+(helper_var_1796.start + 10))) {
    op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
    goto label_1060;
  }
}
Generic helper_var_1828;
if(helper_var_1668.value.tuple.start + 1 < TUPLE_POOL_SIZE && helper_var_1668.value.tuple.start + 1>= 0) {
  unsigned helper_var_1860 = *((*tuple_pool)+(helper_var_1668.value.tuple.start + 1));
  if(helper_var_1860 < HEAP_SIZE && helper_var_1860 >= 0) {
    helper_var_1828 = *(*(heap)+(helper_var_1860));
  } else {
    op_result = (OpResult){.exception = 1, .exception_msg = "HEAP(MatchError) No match of right hand side value."};
    goto label_1060;
  }
} else {
  op_result = (OpResult){.exception = 1, .exception_msg = "TUPLE(MatchError) No match of right hand side value."};
  goto label_1060;
}
int helper_var_1892 = helper_var_1828.value.integer;
int x_1_ = helper_var_1892;

label_1060:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("x: %d", x_1_);
int helper_var_1924 = 0;


  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_1924;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
