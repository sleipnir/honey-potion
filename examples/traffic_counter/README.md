# Traffic Counter

This example counts network traffic by source MAC address using an eBPF hash map. It increments a counter for each packet and demonstrates basic packet processing with Honey Potion.

## How to compile

Run the following commands inside this directory:

```sh
mix format
mix deps.get
mix compile
```


