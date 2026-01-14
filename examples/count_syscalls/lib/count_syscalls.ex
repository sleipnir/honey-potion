defmodule CountSyscalls do
  use Honey, license: "Dual BSD/GPL"

  printlist = [
    {"Syscall: enter_read (0) | Qtt:", 0},
    {"Syscall: enter_write (1) | Qtt:", 1},
    {"SysCall: enter_kill (62) | Qtt:", 62},
    {"SysCall: enter_mkdir (83) | Qtt:", 83},
    # Defines the {"Name", key} of each printed element
    {"SysCall: enter_getrandom (318) | Qtt:", 318}
  ]

  # Defines a map with BPF_MAP_TYPE_ARRAY type, 335 entries and the above printlist
  defmap(:Count_Sys_Calls_Invoked, :bpf_array,
    max_entries: 335,
    print: true,
    print_elem: printlist
  )

  # Sets our trigger to sys_enter
  @sec "tracepoint/raw_syscalls/sys_enter"
  def main(ctx) do
    # Grabs the ID of the sys_enter, which represents what sys_enter call was done
    id = ctx.id

    # Grabs the old value in the map
    id_count = Honey.BpfHelpers.bpf_map_lookup_elem(:Count_Sys_Calls_Invoked, id)
    # and increments it by one
    Honey.BpfHelpers.bpf_map_update_elem(:Count_Sys_Calls_Invoked, id, id_count + 1)
  end
end
