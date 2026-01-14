# Force Kill Example

This example tracks the use of the `kill -9` signal on processes using an eBPF hash map. When a process receives signal 9, it stores the PID in the map for monitoring purposes.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


