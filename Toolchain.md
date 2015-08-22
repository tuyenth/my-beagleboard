[Intro to basic cross-compiling for the BeagleBoard](http://www.electronsonradio.com/2011/04/intro-to-basic-cross-compiling-for-the-beagleboard/)

First make sure you have installed the [packages needed](DebianPackets.md)

#### Cross compiling with [crosstools-ng](http://crosstool-ng.org/) ####
```
hg clone http://crosstool-ng.org/hg/crosstool-ng
cd crosstool-ng
autoconf
./configure (`--prefix=/some/place` if you want to *install* it to a different place than local)
make
sudo make install (in case you want to *install* it and use globally)
```
To see the crosstools help:
  * `./ct-ng help`
To see the available samples:
  * `./ct-ng help list-samples`

Select arm­-unknown­-linux­-gnueabi for BeagleBoard and build:
  * `./ct-ng arm­-unknown­-linux­-gnueabi`
  * `./ct-ng menuconfig`

#### Menuconfig Options (from [Free Electrons](http://free-electrons.com/blog/beagle-labs) practical labs) ####
In Path and misc options:
  * Change the prefix directory to `/usr/local/xtools/toolchain-name`. This is the place where the toolchain will be installed.
  * Change the number of parallel jobs to 2 times the number of CPU cores in your workstation. Building your toolchain will be faster.

In Toolchain options:
  * Set «Tuple's alias» to arm­-linux. This way, we will be able to use the compiler as arm­-linux­-gcc instead of arm­-unknown­-linux­-gnueabi­-gcc, which is much longer.

In C Compiler_* Remove compiling fortran and java_

In Debug facilities:
  * Enable gdb, strace and ltrace. Remove the other options (dmalloc and duma). In gdb options, enable the “Cross gdb” and “Build a static gdbserver” options; the other options are not needed.

#### Build ####
  * `./ct-ng build`

#### Make a dynamic link of the toolchain for later use ####
```
ln -s /usr/local/xtools/toolchain-name /opt/bb/toolchain
```