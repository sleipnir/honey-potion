defmodule DropUdp do
  @moduledoc """
  Documentation for `DropUdp`.
  """

  use Honey, license: "Dual BSD/GPL"

  @sec "xdp_md"
  def main(_ctx) do
    drop_port = 3000
    redirect_port = 3001
    # Should only be called once!
    Honey.Ethhdr.init()
    # Grabs the ip_protocol
    protocol = Honey.Ethhdr.ip_protocol()
    # If it's udp
    if protocol == Honey.Ethhdr.const_udp() do
      # Grab the destination port
      port = Honey.Ethhdr.destination_port()

      cond do
        # Drop port 3000
        port == drop_port -> Honey.XDP.drop()
        # Redirect 3001 to 3000
        port == redirect_port -> Honey.Ethhdr.set_destination_port(drop_port)
        # Do nothing
        true -> 0
      end
    end

    # Pass all other cases
    Honey.XDP.pass()
  end
end
