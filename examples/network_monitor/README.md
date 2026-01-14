# Network Monitor Example

This example monitors network-related syscalls (`sendto`, `sendmsg`, `sendmmsg`, `recvfrom`, `recvmsg`, `recvmmsg`) for each process using eBPF maps. It counts send and receive operations and can alert when a threshold is exceeded.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


