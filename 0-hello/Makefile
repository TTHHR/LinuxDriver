#解决签名问题
CONFIG_MODULE_SIG=n
#如果已经定义KERNELRELEASE，说明是从内核调用的，所以可以直接用内建语句
ifneq ($(KERNELRELEASE),)
	obj-m := hello.o hellop.o
else
#否则就要调用内核构造系统
	KERN_DIR ?= /usr/src/linux-headers-$(shell uname -r)/
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
endif
#清除中间产生的文件
clean:
	rm -rf *.o *.mod.c Module.symvers modules.order




