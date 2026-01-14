# Disk Monitor Example

This example monitors disk I/O syscalls (read, write, pread64, pwrite64, readv, writev) for each process using eBPF maps. It counts how many times each process performs these operations and can be used for real-time disk activity analysis.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


