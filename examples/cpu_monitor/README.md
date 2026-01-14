# Cpu Monitor Example

This example monitors CPU usage per process using eBPF maps. It tracks context switches and accumulates CPU time for each process, printing the results with Honey Potion.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


