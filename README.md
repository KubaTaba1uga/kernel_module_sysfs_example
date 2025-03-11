# show_vas_info

This Linux Kernel Module displays key information about the system's Virtual Address Space (VAS). It prints details for both kernel memory regions and the current process's user space regions.

## Features

- **Kernel VAS Information**  
  Displays addresses and sizes for:
  - Fixed address region (e.g., `FIXADDR_START`)
  - Kernel module area (`MODULES_VADDR` to `MODULES_END`)
  - Vmalloc area (`VMALLOC_START` to `VMALLOC_END`)
  - Direct RAM mapping (`PAGE_OFFSET` to `high_memory`)

- **User VAS Information**  
  Reports details of the current process including:
  - Arguments section (`arg_start` to `arg_end`)
  - Environment section (`env_start` to `env_end`)
  - Heap, data, and text segments

## Building

Ensure you have the required build tools and kernel headers installed, then compile the module with:

```bash
make
```

## Usage

1. **Load the Module**  
   ```bash
   sudo insmod show_vas_info.ko
   ```
2. **View the Kernel Logs**  
   Use `dmesg` to see the output:
   ```bash
   dmesg | tail
   ```
3. **Unload the Module**  
   ```bash
   sudo rmmod show_vas_info
   ```

## License

Dual MIT/GPL

