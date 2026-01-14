# Memory Monitor

This example monitors memory-related syscalls (`mmap`, `munmap`, `brk`) for each process using eBPF maps. It counts how many times each process requests, releases, or adjusts memory.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


