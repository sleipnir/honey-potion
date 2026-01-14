# Drop Udp Example

This example demonstrates how to drop or redirect UDP packets using eBPF and Honey Potion. It inspects the UDP destination port and either drops, redirects, or passes the packet based on its value.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


