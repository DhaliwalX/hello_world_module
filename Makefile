obj-m += wait_hello.o hello.o 
kernel-src-dir ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(kernel-src-dir) M=$(PWD)

clean:
	make -C $(kernel-src-dir) M=$(PWD) clean

