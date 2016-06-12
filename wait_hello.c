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
#include <linux/timer.h>
#include <linux/time.h>

struct timer_list timer;
int i;

void say_hello(unsigned long data)
{
    int tmp;

    i++;
    tmp = i;
    printk(KERN_DEBUG "[%d] Hello there!\n", tmp);
    timer.expires = jiffies + HZ;
    add_timer(&timer);
}

static int hello_init(void)
{
    unsigned long expire = jiffies + HZ;

    init_timer(&timer);
    timer.function = say_hello;
    timer.expires = expire;
    timer.data = 10;
    add_timer(&timer);
    printk(KERN_DEBUG "Hello, World!\n");
    return 0;
}

static void hello_exit(void)
{
    if (!del_timer(&timer)) {
        printk(KERN_DEBUG "Couldn't remove timer!\n");
    } else {
        printk(KERN_INFO "Removed timer\n");
    }
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pushpinder Singh");
MODULE_DESCRIPTION("Hello World Module");
