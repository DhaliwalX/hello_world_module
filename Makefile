<<<<<<< HEAD
obj-m += wait_hello.o hello.o 
kernel-src-dir ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(kernel-src-dir) M=$(PWD)

clean:
	make -C $(kernel-src-dir) M=$(PWD) clean
=======
obj-m += hello.o 
kernel-build-dir := /lib/modules/$(shell uname -r)/build

all:
	make -C $(kernel-build-dir) M=$(PWD) modules

clean:
	make -C $(kernel-build-dir) M=$(PWD) clean
>>>>>>> 7acddc94ee42911ce0e710b80fdbbb39acbf6fb0

