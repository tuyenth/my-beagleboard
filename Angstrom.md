[Building Ångström for the BeagleBoard using OpenEmbedded](http://www.electronsonradio.com/2011/04/building-angstrom-for-the-beagleboard-using-openembedded/)

[Angstrom on the BeagleBoard: Fixing your MAC Address.](http://www.electronsonradio.com/2011/07/angstrom-on-the-beagleboard-fixing-your-mac-address/)

## Narcissus Super Easy Way ##
[Quick start to Angstrom on the BeagleBoard](http://www.electronsonradio.com/2012/02/quick-start-to-angstrom-on-the-beagleboard/)

http://narcissus.angstrom-distribution.org/

## One Way ##
http://www.angstrom-distribution.org/building-angstrom
```
git clone git://git.angstrom-distribution.org/setup-scripts oebb
. /home/dani/.oe/environment-angstromv2012.05
export MACHINE=beagleboard
cd oebb
./oebb.sh config beagleboard
./oebb.sh update
bitbake virtual/kernel -c menuconfig
bitbake virtual/kernel -c compile -f
bitbake virtual/kernel
```
From https://groups.google.com/forum/?fromgroups#!topic/beagleboard/UlL4e0_O_UE
```
bitbake virtual/kernel -c configure
cd tmp/work/foo/bar/git
make menuconfig
cp .config /OE/openembedded/recipes/linux/linux-omap-<version>/<machine>/defconfig
bitbake virtual/kernel -c compile -f
bitbake virtual/kernel -c deploy
goto 2)
```
Step 3 is there to ensure that my changes don't get lost when cleaning the recipe.


## Another Way ##
```
git clone git://gitorious.org/angstrom/angstrom-linux.git
cd angstrom-linux
git checkout 12ca45fea91cfbb09df828bea958b47348caee6d # beagleboardXM branch
```
#optional for SPI. See [this](http://linuxdeveloper.blogspot.com.es/2011/10/enabling-spi-on-beagleboard-xm.html)
```
git checkout -b spi 
```
```
export PATH=/opt/bb/toolchain/bin:$PATH
export ARCH=arm ; export CROSS_COMPILE=arm-unknown-linux-gnueabi-
make mrproper
make omap3_beagle_defconfig
make menuconfig
make uImage
```