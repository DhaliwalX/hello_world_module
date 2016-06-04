obj-m += hello.o 
kernel-build-dir := /lib/modules/$(shell uname -r)/build

all:
	make -C $(kernel-build-dir) M=$(PWD) modules

clean:
	make -C $(kernel-build-dir) M=$(PWD) clean

