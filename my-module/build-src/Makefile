# SPDX-License-Identifier: GPL-2.0

obj-m += my-module.o

my-module-objs := my-module-main.o


all:
	$(MAKE) -Wall -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)  modules

modules_install :
	$(MAKE) -Wall -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) -Wall M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@
