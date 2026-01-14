defmodule ForceKill do
  @moduledoc """
  Documentation for `ForceKill`.
  """

  use Honey, license: "Dual BSD/GPL"

  # Defines an eBPF map of the BPF_MAP_TYPE_HASH with 64 entries
  defmap(:ForceKills, :bpf_hash, max_entries: 64, print: true)

  # Sets our trigger to be sys_enter_kill
  @sec "tracepoint/syscalls/sys_enter_kill"
  def main(ctx) do
    # Grabs the sig and pid from the ctx variable
    sig = ctx.sig
    pid = ctx.pid
    # What sig we wish to count. In this case 9
    target_sig = 9
    # Any integer arbitrary value works!
    stored_value = 1

    cond do
      # In case the kill had the sig of 9 or <target_sig> (kill -9 <PID>)
      sig == target_sig ->
        # Stores a value into the <pid> key. It will be printed from now on.
        Honey.BpfHelpers.bpf_map_update_elem(:ForceKills, pid, stored_value, :BPF_NOEXIST)
    end

    0
  end
end
