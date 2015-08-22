Info obtained from: http://elinux.org/BeagleBoard#X-Loader

Steve did some work to consolidate and update X-Loader from various sources and put it in a [X-Loader git repository](http://gitorious.org/x-load-omap3). Get it by:
```
git clone git://gitorious.org/x-loader/x-loader.git xloader
cd xloader
```
Build:
```
export PATH=/opt/bb/toolchain/bin:$PATH
export ARCH=arm ; export CROSS_COMPILE=arm-linux-
make distclean
make omap3530beagle_config 
make
```
Result will be a ~20k sized MLO in the main directory. This is the signed x-loader and is ready for use.