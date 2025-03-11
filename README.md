# sysfs_example

A minimal Linux kernel module that demonstrates sysfs integration.

## Overview

Creates a sysfs entry at `/sys/kernel/my_kobject` with a read-only attribute `my_attr`.

## Build & Usage

- **Build:**  
  ```bash
  make
  ```

- **Load Module:**  
  ```bash
  sudo insmod sysfs_example.ko
  ```

- **Verify Attribute:**  
  ```bash
  cat /sys/kernel/my_kobject/my_attr
  ```

- **Unload Module:**  
  ```bash
  sudo rmmod sysfs_example
  ```

## License

Dual MIT/GPL
