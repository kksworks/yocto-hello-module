
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h> /* Needed for KERN_INFO */


MODULE_AUTHOR("Tom Lendacky <thomas.lendacky@amd.com>");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("hello world");


static int __init my_module_init(void)
{
	printk(KERN_INFO "Hello, World!\n");
	return 0;
}

static void __exit my_module_exit(void)
{
	printk(KERN_INFO "Goodbye, World!\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
