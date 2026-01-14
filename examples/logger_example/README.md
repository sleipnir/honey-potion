# Logger Example

This example demonstrates how to use Elixir's Logger in Honey Potion eBPF programs. Logger calls are translated to bpf_printk with log level prefixes, showing how to log at different levels and control packet flow.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


