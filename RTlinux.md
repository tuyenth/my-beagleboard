https://rt.wiki.kernel.org/index.php/RT_PREEMPT_HOWTO

https://www.osadl.org/Realtime-Preempt-Kernel.kernel-rt.0.html

https://groups.google.com/d/msg/beagleboard/i1YGBYbMYuk/oZnxT6I5W54J

http://www.kernel.org/pub/linux/kernel/projects/rt/

https://rt.wiki.kernel.org/



## Make a RT linux kernel ##

  1. Download the linux kernel and the patch (2.33.7 in this example)
  * `wget http://www.kernel.org/pub/linux/kernel/v2.6/linux-2.6.33.7.tar.bz2`
  * `wget http://www.kernel.org/pub/linux/kernel/projects/rt/2.6.33/older/patch-2.6.33.7-rt29.bz2`
  * `tar -xjvf linux-2.6.33.7.tar.bz2`
  * `bunzip2 patch-2.6.33.7-rt29.bz2`
  * `cd linux-2.6.33.7`
  * `patch -p1 <../patch-2.6.33.7-rt29`

Follow the intructions to compile the kernel in [Kernel](Kernel.md)