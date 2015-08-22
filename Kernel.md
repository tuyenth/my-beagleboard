[Course: Introduction to Linux kernel programming (2nd edition)](http://crashcourse.ca/introduction-linux-kernel-programming-2nd-edition/introduction-linux-kernel-programming-2nd-edition)

[Interactive map of Linux kernel](http://www.makelinux.net/kernel_map/)

[BeagleBoard Kernel compiling HowTo](http://www.eewiki.net/display/linuxonarm/BeagleBoard)

http://elinux.org/BeagleBoardLinuxKernel

## Cross Compile a Kernel ##
In any kernel, under `arch/xxx/configs/` are all the default configurations, given that xxx is the architechture we want to build the kernel for.

In kernel 2.6.31.6 and beagleboard we have `arch/arm/configs/omap3_beagle_defconfig`

We also need a toolchain compiled (¿for that kernel?) for that arch with crosstools-ng:

  * `export PATH=/opt/bb/toolchain/bin:$PATH`
  * `export ARCH=arm ; export CROSS_COMPILE=arm-unknown-linux-gnueabi-`
  * `make mrproper`
  * `make omap3_beagle_defconfig`
  * `make menuconfig`
  * `make uImage`

**NOTE:** `make uImage` may fail with a misleading success message: `"mkimage" command not found - U-Boot images will not be built
Image arch/arm/boot/uImage is ready`

`mkimage` is a tool built as part of U-Boot and needs to be in your PATH.
[build U-Boot first](Uboot.md) end export its tools path
