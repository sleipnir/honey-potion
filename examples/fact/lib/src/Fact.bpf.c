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
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:587
int helper_var_41 = ctx_arg->id;


op_result.exception = 0;
int id_2_ = helper_var_41;

label_9:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139
int helper_var_105 = 3;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139
int helper_var_137 = 2;
int helper_var_169 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_201 = helper_var_137 * helper_var_169;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_233 = helper_var_105 * helper_var_201;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_265 = {0};
 helper_var_265.type = INTEGER; helper_var_265.value.integer = helper_var_233;

op_result.exception = 0;
Generic a_3_ = helper_var_265;

label_73:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797


op_result.exception = 0;
int x_0_Fuel2_195 = id_2_;

label_329:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:736
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_361 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_393;
if (x_0_Fuel2_195 == helper_var_361){
  helper_var_393 = ATOM_TRUE;
} else {
  helper_var_393 = ATOM_FALSE;
}



Generic helper_var_425;
op_result.exception = 0;
if(helper_var_393.type != ATOM || helper_var_393.value.string.start != 3 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_457;
}

label_457:
if(op_result.exception == 0) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139



// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_521 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1633
int helper_var_553 = x_0_Fuel2_195 - helper_var_521;


op_result.exception = 0;
int x_0_Fuel1_259 = helper_var_553;

label_489:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:736
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_585 = 1;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_617;
if (x_0_Fuel1_259 == helper_var_585){
  helper_var_617 = ATOM_TRUE;
} else {
  helper_var_617 = ATOM_FALSE;
}



Generic helper_var_649;
op_result.exception = 0;
if(helper_var_617.type != ATOM || helper_var_617.value.string.start != 3 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_681;
}

label_681:
if(op_result.exception == 0) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:624
Generic helper_var_713 = (Generic){0};
op_result = (OpResult){ .exception = 1, .exception_msg = "(RaiseException) Provide more fuel!"};
goto CATCH;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1612
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_777 = {0};
 helper_var_777.type = INTEGER; helper_var_777.value.integer = x_0_Fuel1_259;

BINARY_OPERATION(helper_var_745, Multiply, helper_var_777, helper_var_713)


  
  helper_var_649 = helper_var_745;
} else {
  op_result.exception = 0;
if(helper_var_617.type != ATOM || helper_var_617.value.string.start != 8 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_809;
}

label_809:
if(op_result.exception == 0) {
  int helper_var_841 = 1;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_873 = {0};
 helper_var_873.type = INTEGER; helper_var_873.value.integer = helper_var_841;

  helper_var_649 = helper_var_873;
} else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(CaseClauseError) no case clause matching."};
  goto CATCH;

}

}



// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1612
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_937 = {0};
 helper_var_937.type = INTEGER; helper_var_937.value.integer = x_0_Fuel2_195;

BINARY_OPERATION(helper_var_905, Multiply, helper_var_937, helper_var_649)


  
  helper_var_425 = helper_var_905;
} else {
  op_result.exception = 0;
if(helper_var_393.type != ATOM || helper_var_393.value.string.start != 8 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_969;
}

label_969:
if(op_result.exception == 0) {
  int helper_var_1001 = 1;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1033 = {0};
 helper_var_1033.type = INTEGER; helper_var_1033.value.integer = helper_var_1001;

  helper_var_425 = helper_var_1033;
} else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(CaseClauseError) no case clause matching."};
  goto CATCH;

}

}




op_result.exception = 0;
Generic b_4_ = helper_var_425;

label_297:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1589
BINARY_OPERATION(helper_var_1097, Sum, a_3_, b_4_)


op_result.exception = 0;
Generic c_5_ = helper_var_1097;

label_1065:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:191

bpf_printk("%d", c_5_.value.integer);
int helper_var_1129 = 0;


  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return helper_var_1129;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
