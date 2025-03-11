/*
 * sysfs_example.c
 ****************************************************************
 * Brief Description:
 * A very simple module which expose some of it's attributes via sysfs.
 * Look into Documentation/filesystems/sysfs.rst first.
 * First we need to understand what kobj is and how to create/destroy one.
 * Read everything-you-never-wanted-to-know-about-kobjects-ksets-and-ktypes
 * and https://lwn.net/Articles/51437/.
 */

#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("KubaTaba1uga");
MODULE_DESCRIPTION("a simple LKM showing how expose your data via sysfs");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

// We need this declaration to create and destroy kobj.
// We need kobj to expose it via sysfs and with it our custom data.
static struct kobject *my_kobj;
static int counter = 0;

static ssize_t my_show(struct kobject *kobj, struct kobj_attribute *attr,
                       char *buf) {
  return sprintf(buf, "%d\n", counter++);
}

static struct kobj_attribute my_attr = __ATTR(my_attr, 0440, my_show, NULL);

static int __init sysfs_example_init(void) {
  pr_info("Inserted\n");

  // "my_kobject" is name under which obj will be exposed under:
  //   /sys/kernel/
  my_kobj = kobject_create_and_add("my_kobject", kernel_kobj);
  if (!my_kobj)
    return -ENOMEM;

  // This function creates file for our attribute, it bounds kobj and
  //   kobj_attribute together.
  return sysfs_create_file(my_kobj, &my_attr.attr);
}

static void __exit sysfs_example_exit(void) {
  kobject_put(my_kobj);
  pr_info("Removed\n");
}

module_init(sysfs_example_init);
module_exit(sysfs_example_exit);
