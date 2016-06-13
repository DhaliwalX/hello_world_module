/*
 * A simple `Hello, World` module that when loaded prints
 * to the kernel debug log level, "Hello, World!"
 * References: 
 *    1) Linux Kernel Development By Robert Love
 *    2) Linux Source Code (Documentation/kbuild)
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
    printk(KERN_DEBUG "Hello, World!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_DEBUG "I am exiting now!\n");
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pushpinder Singh");
MODULE_DESCRIPTION("Hello World Module");
