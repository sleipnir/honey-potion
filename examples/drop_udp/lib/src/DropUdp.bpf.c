// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:33
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:343
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <stddef.h>
#include <runtime_structures.bpf.h>
#include <runtime_functions.bpf.c>

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:356
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/icmp.h>
#include <arpa/inet.h>
#include <linux/udp.h>
#include <linux/tcp.h>

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:677
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:685
char LICENSE[] SEC("license") = "Dual BSD/GPL";


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:719
SEC("xdp_md")
int main_func(struct xdp_md *ctx_arg) {
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
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:466
void *data_end = (void *)(long)ctx_arg->data_end;
void *data = (void *)(long)ctx_arg->data;
struct ethhdr *eth = data;

__u64 nh_off = sizeof(*eth);

if (data + nh_off > data_end)
return XDP_ABORTED;

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:499
int helper_var_805;
if (eth->h_proto == htons(ETH_P_IP)){
    struct iphdr *iph = data + nh_off;

    // Again verifier check our boundary checks
    if (data + nh_off + sizeof(struct iphdr) > data_end)
        return 0;

    nh_off += sizeof(struct iphdr);
    helper_var_805 = iph->protocol;
} else if (eth->h_proto == htons(ETH_P_IPV6)) {

    struct ipv6hdr *ip6h = data + nh_off;

    // Again verifier check our boundary checks
    if (data + nh_off + sizeof(struct ipv6hdr) > data_end)
        return 0;

    nh_off += sizeof(struct ipv6hdr);
    helper_var_805 = ip6h->nexthdr;
} else {
    return XDP_PASS;
}


op_result.exception = 0;
int protocol_3_ = helper_var_805;

label_773:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:736
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_869;
if (protocol_3_ == IPPROTO_UDP){
  helper_var_869 = ATOM_TRUE;
} else {
  helper_var_869 = ATOM_FALSE;
}



Generic helper_var_901;
op_result.exception = 0;
if(helper_var_869.type != ATOM || helper_var_869.value.string.start != 3 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_933;
}

label_933:
if(op_result.exception == 0) {
  Generic helper_var_965 = ATOM_NIL;
  
  helper_var_901 = helper_var_965;
} else {
  op_result.exception = 0;
if(helper_var_869.type != ATOM || helper_var_869.value.string.start != 8 ) {
  op_result = (OpResult){.exception = 1, .exception_msg = "(MatchError) No match of right hand side value."};
  goto label_997;
}

label_997:
if(op_result.exception == 0) {
  

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:797
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:513
int helper_var_1061;
{
struct udphdr *udph = data + nh_off;

if (data + nh_off + sizeof(struct udphdr) > data_end)
    return 0;
helper_var_1061 = ntohs(udph->dest);
}


op_result.exception = 0;
int port_4_ = helper_var_1061;

label_1029:
if(op_result.exception == 1) {
  goto CATCH;
}

// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:641
Generic helper_var_1093 = {.type = INTEGER, .value.integer = 0};
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1125 = 3000;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_1157;
if (port_4_ == helper_var_1125){
  helper_var_1157 = ATOM_TRUE;
} else {
  helper_var_1157 = ATOM_FALSE;
}


  if (to_bool(&helper_var_1157)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:551
return XDP_DROP;

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1189 = {0};
 helper_var_1189.type = INTEGER; helper_var_1189.value.integer = XDP_DROP;

  helper_var_1093 = helper_var_1189;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:139

int helper_var_1221 = 3001;
// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1628
Generic helper_var_1253;
if (port_4_ == helper_var_1221){
  helper_var_1253 = ATOM_TRUE;
} else {
  helper_var_1253 = ATOM_FALSE;
}


  if (to_bool(&helper_var_1253)) {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:529
int helper_var_1317 = 3000;
{
struct udphdr *udph = data + nh_off;

if (data + nh_off + sizeof(struct udphdr) <= data_end)
    udph->dest = ntohs(helper_var_1317);
}

  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1349 = {0};
 helper_var_1349.type = INTEGER; helper_var_1349.value.integer = helper_var_1317;

  helper_var_1093 = helper_var_1349;
} else {
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1535
  Generic helper_var_1381 = ATOM_TRUE;
  if (to_bool(&helper_var_1381)) {
  int helper_var_1413 = 0;
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:1674
 Generic helper_var_1445 = {0};
 helper_var_1445.type = INTEGER; helper_var_1445.value.integer = helper_var_1413;

  helper_var_1093 = helper_var_1445;
} else {
  helper_var_1093 = (Generic){.type = ATOM, .value.string = (String){0, 2}};
}

}

}



  
  helper_var_901 = helper_var_1093;
} else {
    op_result = (OpResult){.exception = 1, .exception_msg = "(CaseClauseError) no case clause matching."};
  goto CATCH;

}

}


// Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/compiler/translator.ex:558
return XDP_PASS;


  // =============== end of user code ==============
  // Generated at /home/adrianosantos/workspaces/git/me/honey-potion/lib/honey/codegen/boilerplates.ex:570
return XDP_PASS;
CATCH:
  bpf_printk("** %s\n", op_result.exception_msg);
  return 0;

}
