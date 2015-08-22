There are blocks of code in Linux that disable interrupts and hence the responsiveness of Linux is not deterministic. There are real-time extensions for the Linux Kernel that break up these large blocks of code and this makes Linux more deterministic, but you have to know what you are doing to make this work. Another approach is to use a processor like the one on the Beagle-xM or PandaBoard which have an ARM and DSP processor. On the DSP processor, you use [SysBios real-time OS](http://www.ti.com/tool/sysbios) and [SysLink for communications between Linux and the DSP](http://omappedia.org/wiki/Syslink_Project). Unfortunately, SysLink does not work with the latest Linux Kernels (currently only supports 2.6.32). There is new work in the Linux Kernel v3.4 where SysLink is replaced with RPMSG (SysLInk3) but currently there is only support for OMAP4. RPMSG also enables the support of virtual I/O. There is work being done on RPMSG to add support for OMAP3 and OMAPL138.

http://veter-project.blogspot.com.es/2011/09/real-time-enough-about-pwms-and-shaky.html

[RTAI patch for ARM Cortex-A8](http://rtai-cortex.sourceforge.net/)

http://saroshshahbuddin.wordpress.com/2011/05/15/beagleboard-xm-real-time-audio-processing/

http://processors.wiki.ti.com/index.php/Realtime