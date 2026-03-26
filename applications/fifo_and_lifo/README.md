# General informations
This is demo application to demonstrate use of FIFO and LIFO queues. 

# Supported platforms
- native_sim

# Build command

```
west build -p always applications/fifo_and_lifo/ --board native_sim --build-dir build_fifo
```

# How it works

There are two threads:

- `producer_thread_fn`: allocates dynamic `sensor_data`, updates values, then pushes the pointer into `telemetry_fifo` with `k_fifo_put()`.
- `consumer_thread_fn`: takes items from `telemetry_fifo` with `k_fifo_get()`, logs them, and calls `k_free()` to release memory.

The app demonstrates Zephyr FIFO queue usage with heap allocation (`k_malloc`/`k_free`) and inter-thread synchronization. As you can see, the data that `consumer` receives points to the same memory region that data sends by `producer` if FIFO fashion, which means that this FIFO queueu use refrerence to the data, instead of copy (like it's done with message queues).

> Note: Ensure `CONFIG_HEAP_MEM_POOL_SIZE` is set in `prj.conf` to use `k_malloc()` correctly.



