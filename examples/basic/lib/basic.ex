defmodule Basic do
  @moduledoc """
  Documentation for `Basic`.
  """
  use Honey, license: "Dual BSD/GPL"

  @sec "tracepoint/raw_syscalls/sys_enter"
  def main(_) do
    # This is a temporary example to test the most basic of compilations.
    x = 1
    x
  end
end
