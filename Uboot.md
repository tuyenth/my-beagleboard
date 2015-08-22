Info from http://elinux.org/BeagleBoard#U-Boot

[Mainline U-Boot](http://www.denx.de/wiki/U-Boot/WebHome) has good support for BeagleBoard (except for revision C4; see note below). Get it by:
```
git clone git://git.denx.de/u-boot.git u-boot-main
cd u-boot-main
git checkout --track -b omap3 origin/master
```

Build (assuming Code Sourcery GCC):
```
export PATH=/opt/bb/toolchain/bin:$PATH
export ARCH=arm ; export CROSS_COMPILE=arm-linux-
make mrproper
make omap3_beagle_config
make
```
Result will be a ~160k sized u-boot.bin in main directory.

Note: Due to (patch and binary) size, BeagleBoard splash screen was removed from upstream version. If you want it back, use U-Boot v1 BeagleBoard splash screen patch.

Note: For experimental U-Boot patches not ready for mainline yet, Steve's Beagle U-Boot git repository is used to test them. Get it by:

  * `git clone git://gitorious.org/u-boot-omap3/mainline.git u-boot-omap3`
  * `cd u-boot-omap3`
  * `git checkout --track -b omap3-dev origin/omap3-dev`

**Note**: For changing the screen resolution there is one option modifying the file in "include/configs/omap3\_beagle.h" and adjusting the maximum resolution before compiling as describe in ARM OMAP2/3 Display Subsystem


**Note**: For beagleboard revision C4, above sources will not work. USB EHCI does not get powered, hence devices are not detected... get a patched version of u-boot from [here](http://gitorious.org/beagleboard-default-u-boot/beagle_uboot_revc4/) (Update on April 23 - 2010: This repository has been superseded by the U-Boot version found at [here](http://gitorious.org/beagleboard-validation/))


**Note**: If you want to activate I2C from the expansion header, modify board/ti/beagle/beagle.h :

  * `MUX_VAL(CP(I2C2_SCL),		(IEN  | PTU | EN | M4)) /*GPIO_168*/`
  * `MUX_VAL(CP(I2C2_SDA),		(IEN  | PTU | EN | M4)) /*GPIO_183*/`

to

  * `MUX_VAL(CP(I2C2_SCL),		(IEN  | PTU | DIS | M0)) /*I2C2_SCL*/`
  * `MUX_VAL(CP(I2C2_SDA),		(IEN  | PTU | DIS | M0)) /*I2C2_SDA*/`