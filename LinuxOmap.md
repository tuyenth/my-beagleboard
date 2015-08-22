Info obtained from http://elinux.org/BeagleBoard#Linux_kernel

[Git repository](http://git.kernel.org/?p=linux/kernel/git/tmlind/linux-omap.git;a=summary) of [OMAP Linux kernel](http://muru.com/linux/omap/) contains Beagle support. Get it by:

  * `git clone git://git.kernel.org/pub/scm/linux/kernel/git/tmlind/linux-omap.git linux-omap`
  * `cd linux-omap`

Build:

  * `export ARCH=arm`
  * `make distclean`
  * `make omap2plus_defconfig`
  * `make menuconfig`  # only needed if you want to change the default configuration
  * `make uImage`

The result will be a uImage in arch/arm/boot/ directory.

If you use the OE toolchain (or any other) and want to build outside of the OE tree you should do:

  * `export PATH=/opt/bb/toolchain/bin:$PATH`
  * `export ARCH=arm ; export CROSS_COMPILE=arm-unknown-linux-gnueabi-`
  * `make distclean`
  * `make omap3_beagle_defconfig`
  * `make menuconfig`  # only needed if you want to change the default configuration
  * `make uImage`

**Note**: the staging dir in the path is for mkimage. If you've built a kernel before with oe, the program should be there

**Note**: If you are interested in kernel development have a look to manually compiling BeagleBoard kernel, too.
Experimental kernel patches and hacks

Some beagle developers maintain their own kernel experimental patches and hacks not ready for upstream:

  * [Koen's collection of kernels patches for OE](http://cgit.openembedded.net/cgit.cgi?url=openembedded/tree/packages/linux/linux-omap) and the [list of relevant patches](http://cgit.openembedded.net/cgit.cgi?url=openembedded/tree/packages/linux/linux-omap_git.bb)
  * [Steve's kernel tree](http://www.sakoman.net/cgi-bin/gitweb.cgi?p=linux-omap-2.6.git;a=shortlog;h=refs/heads/test), a clone of main OMAP git with additional patches, mainly beagle audio (ASOC) related.
  * [Mans' kernel tree](http://git.mansr.com/?p=linux-omap;a=summary), a clone of main OMAP git with additional patches, mainly display & framebuffer related.
  * [Tomi's kernel tree](http://www.bat.org/~tomba/linux-omap.html), a clone of main OMAP git with display sub-system patches, replacing the entire display driver with one that is the likely direction moving forward.