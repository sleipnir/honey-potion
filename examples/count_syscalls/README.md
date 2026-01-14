# Count Syscalls Example

This example counts the number of times each system call is invoked using an eBPF array map. It tracks specific syscalls and prints their counts using Honey Potion.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


