/*
 * sysfs_example.c
 ****************************************************************
 * Brief Description:
 * A very simple module which expose some of it's attributes via sysfs.
 *
 */

#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("KubaTaba1uga");
MODULE_DESCRIPTION("a simple LKM showing how expose your data via sysfs");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int __init sysfs_example_init(void) {
  pr_info("Inserted\n");

  return 0;
}

static void __exit sysfs_example_exit(void) { pr_info("Removed\n"); }

module_init(sysfs_example_init);
module_exit(sysfs_example_exit);
