http://www.youtube.com/watch?v=qzB-PKXW5ZU

For latest stable:
http://www.kernel.org/pub/linux/kernel







For installing:
http://kernel.ubuntu.com/~kernel-ppa/mainline

daniko@dlopezar:/lib/modules$ ll
total 20
drwxr-xr-x 4 root root 4096 2011-11-18 22:07 2.6.32-33-generic







drwxr-xr-x 4 root root 4096 2011-11-18 19:50 2.6.32-35-generic
drwxr-xr-x 5 root root 4096 2012-03-01 12:21 2.6.32-38-generic
drwxr-xr-x 5 root root 4096 2012-03-15 16:56 2.6.32-39-generic
drwxr-xr-x 5 root root 4096 2012-03-23 08:42 2.6.32-40-generic






daniko@dlopezar:~$ cat /etc/lsb-release
DISTRIB\_ID=Ubuntu
DISTRIB\_RELEASE=10.04
DISTRIB\_CODENAME=lucid
DISTRIB\_DESCRIPTION="Ubuntu 10.04.4 LTS"

Before install:
daniko@dlopezar:/lib/modules$ uname -a
Linux dlopezar 2.6.32-39-generic #87~ppa1~loms~lucid-Ubuntu SMP Wed Mar 14 12:37:07 UTC 2012 i686 GNU/Linux


After install:
daniko@dlopezar:~$ uname -a
Linux dlopezar 3.2.12-030212-generic #201203191306 SMP Mon Mar 19 17:22:19 UTC 2012 i686 GNU/Linux


- 1 - Go to this website http://kernel.ubuntu.com/~kernel-ppa/mainline/ and you'll see a huge directory tree of kernels. Find the directory for the kernel you want/need and click on it.

-
> 2 - In each of these directories you're going to see "BUILD.LOG",
"CHANGES", three items that begin with "linux-headers", two that begin
with "linux-image" and one that begins with "linux-source".

- 3 -
> Download and then install the following IN THIS ORDER: first get the
linux-headers file that ends with "all.deb". Second get the
linux-headers file that ends with "i386.deb" or "amd64.deb" depending
upon what architecture you need. Finally get the linux-image file that
ends with "i386.deb" or "amd64.deb" again depending upon what
architecture you need. Honestly it doesn't really matter what order you
download them in, but you need to make absolutely sure that you install
them in this order.