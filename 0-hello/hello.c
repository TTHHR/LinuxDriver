#include <linux/init.h>
#include <linux/module.h>
//许可证
MODULE_LICENSE("Dual BSD/GPL");

//启动代码
static int hello_init(void)
{
    printk(KERN_ALERT "Hello, world\n");
    return 0;
}

//退出代码
static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

//留给系统的接口
module_init(hello_init);
module_exit(hello_exit);
