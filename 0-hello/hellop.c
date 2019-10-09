#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
//许可证
MODULE_LICENSE("Dual BSD/GPL");

static char *FLAG="hellop";

static char *message="hello i am driver!";

static int many=1;


//启动代码
static int hellop_init(void)
{
    int i=0;
    for(; i<many; i++)
        printk(KERN_ALERT "%s :%d %s\n",FLAG,i,message);
    return 0;
}

//退出代码
static void hellop_exit(void)
{
    printk(KERN_ALERT "%s :Goodbye, cruel world\n",FLAG);
}

//留给系统的启动接口
module_init(hellop_init);
//留给系统的卸载接口
module_exit(hellop_exit);
//留给系统的参数接口
module_param(many,int,S_IRUGO);
//留给系统的参数接口
module_param(message,charp,S_IRUGO);
