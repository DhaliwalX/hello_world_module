# A Simple Hello World Module for Linux
A simple `Hello, World` module that when loaded prints to the kernel debug log level, __"Hello, World!"__.

## Compiling
You'll need linux-headers for that. On Ubuntu, you can get by using

```
$ sudo apt-get install build-essentials linux-headers-$(uname -r)
```

After that just run `make` command!

__NOTE__: You'll also need to set the kernel log level to 7 (i.e. KERN_DEBUG). That you can do by setting `GRUB_CMDLINE_LINUX="loglevel=7"` in `/etc/default/grub` file.

## Loading
Follow these steps:

* Open terminal (<kbd>Ctrl</kbd><kbd>Alt</kbd><kbd>T</kbd>).

* Type the following command:
```
    $ sudo insmod hello.ko
```

* Now the module will be loaded and see the result using `dmesg | tail`.
* Unloading the module:
```
    $ sudo rmmod hello.ko
```

