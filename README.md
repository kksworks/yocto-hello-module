# yocto-hello-module


## 레시피 추가

다음과같이 예제 레시피(`my-module.bb`)를 만든다.

```sh
# Copyright 2017,2018 ???
SUMMARY = "my-module"
LICENSE = "CLOSED"

BB_STRICT_CHECKSUM = "0"

inherit module

# SJA for kernel 4.14
#SRC_URI = "file://brcm-xgbe_${PV}.tar.gz"

SRC_URI = "file://* "
S = "${WORKDIR}/build-src"

RPROVIDES_${PN} += "my-module"

do_package_qa() {
	:
}

```

- `inherit module` : 모듈 빌드할것을 명시
- `LICENSE = "CLOSED"` : 라이센스는 closed 로해서 라이센스 빌드 관련 내용 스킵
- `SRC_URI` / `S` : 욕토 내부의 파일을 카피하여 빌드


## 소스코드

yocto 의 `build-src` 폴더에 다음의 파일들을 만든다.

> bb 파일에서 명시해준 폴더에 파일들을 작성

```Makefile
# SPDX-License-Identifier: GPL-2.0

obj-m += my-module.o

my-module-objs := my-module-main.o


all:
	$(MAKE) -Wall -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE)  modules

modules_install :
	$(MAKE) -Wall -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) -Wall M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) $@

```

- `KERNEL_SRC`, `PWD` 등의 환경변수들은 yocto system 에서 넘어온다.

```c
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
```

- 기본 모듈예제코드
