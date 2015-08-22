http://beagleboard.org/pru

**[First steps with the BeagleBone PRU](http://boxysean.com/blog/2012/08/12/first-steps-with-the-beaglebone-pru/)**

[BeagleBone Black PRU: Hello World](http://mythopoeic.org/bbb-pru-minimal/)

[libpruio](http://www.freebasic.net/forum/viewtopic.php?f=14&t=22501)

[libpruio tutorial](https://groups.google.com/d/msg/beagleboard/9NYdGWOT_Mg/6X0v2XVEeUAJ)

[BeagleBone Black: Introduction to PRU-ICSS](http://analogdigitallab.org/articles/beaglebone-black-introduction-pru-icss)

[Using the Beaglebone PRU to achieve realtime at low cost](http://www.embeddedrelated.com/showarticle/586.php)

[PRU C Project - from device tree to program execution](https://www.mail-archive.com/beagleboard@googlegroups.com/msg21682.html)

http://hipstercircuits.com/category/pru/

[Beaglebone PRU DDR memory access - the right way](http://hipstercircuits.com/beaglebone-pru-ddr-memory-access-the-right-way)

[Using the C language to program the am335x PRU](http://www.embeddedrelated.com/showarticle/603.php)

[BeagleBone Tutorial: Accessing Main Memory From the PRU (and visa versa)](http://nomel.tumblr.com/post/30006622413/beaglebone-tutorial-accessing-main-memory-from)

[PRUSS System Events and ARM Interrupts (slides)](https://docs.zoho.com/show/publish/b0tmjd21ccd2824464d57afaede48a96dd18f)


## Texas Instruments ##
  * [TI PRU-ICSS Main Page](http://processors.wiki.ti.com/index.php/PRU-ICSS)

  * [Programmable Realtime Unit Subsystem Documentation](http://processors.wiki.ti.com/index.php/Programmable_Realtime_Unit_Subsystem)
    1. [PRU Subsystem Training Material (slides)](http://processors.wiki.ti.com/images/1/18/PRUSS_Training_Slides.pdf)
    1. [PRU Hardware Documentation](http://processors.wiki.ti.com/index.php/Programmable_Realtime_Unit)
      * [PRUSS Memory Map](http://processors.wiki.ti.com/index.php/PRUSS_Memory_Map)
      * [PRU Core Execution Unit](http://processors.wiki.ti.com/index.php/Programmable_Realtime_Unit)
      * [PRU Interrupt Controller](http://processors.wiki.ti.com/index.php/PRU_Interrupt_Controller)
    1. [PRU Software Development](http://processors.wiki.ti.com/index.php/Programmable_Realtime_Unit_Software_Development)
      * [PRU Software Package](http://www.ti.com/tool/pru-swpkg)
      * [PRU Assembly Instructions](http://processors.wiki.ti.com/index.php/PRU_Assembly_Instructions)
      * [App API Loader](http://processors.wiki.ti.com/index.php/PRU_Linux_Application_Loader_API_Guide)
      * [UART with PRU](http://processors.wiki.ti.com/index.php/Soft-UART_Implementation_on_AM335X_PRU_-_Software_Users_Guide)

http://processors.wiki.ti.com/index.php/PRU_Projects

## eLinux ##
  * http://elinux.org/BeagleBone_PRU_Notes
  * http://elinux.org/Ti_AM33XX_PRUSSv2
  * http://elinux.org/PRUSSv2_Interrupt_Controller
  * http://elinux.org/ECE497_BeagleBone_PRU


[PRU Tutorial](http://www.element14.com/community/community/knode/single-board_computers/next-gen_beaglebone/blog/2013/05/22/bbb--working-with-the-pru-icssprussv2)



## Google Groups ##
  * [PRU FAQ](https://groups.google.com/forum/#!topic/beagleboard/u28ytaoNenU)
  * [How to enable PRU](https://groups.google.com/d/msg/beagleboard/odaLOnObjoE/yTykz_wFEHoJ)
  * [PRU BeagleBoad Group](https://groups.google.com/forum/#!categories/beagleboard/pru)

## Github ##
  * [App Examples](https://github.com/beagleboard/am335x_pru_package)

  * [Documentation](https://github.com/beagleboard/am335x_pru_package/tree/master/Documentation)

http://comments.gmane.org/gmane.comp.hardware.beagleboard.general/23748

### [C Initialization](http://processors.wiki.ti.com/index.php/PRU_Linux_Application_Loader_API_Guide#Skeleton_Application_Code) ###
```
/* Driver header file */
   #include <prussdrv.h>
   #include <pruss_intc_mapping.h> 
   
   #define PRU_NUM 	0
   
   /* IRQ handler thread */
   void *pruevtout0_thread(void *arg) {
       do {
          prussdrv_pru_wait_event (PRU_EVTOUT_0);
          prussdrv_pru_clear_event (PRU0_ARM_INTERRUPT);
       } while (1);
   }
   
   void main (void)
   {
       /* Initialize structure used by prussdrv_pruintc_intc   */
       /* PRUSS_INTC_INITDATA is found in pruss_intc_mapping.h */
       tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
   
       /* Allocate and initialize memory */
       prussdrv_init ();		
       prussdrv_open (PRU_EVTOUT_0);
       
       /* Map PRU's INTC */
       prussdrv_pruintc_init(&pruss_intc_initdata);
       
       /* Load and execute binary on PRU */
       prussdrv_exec_program (PRU_NUM, "./PRU_example.bin");
       
       /* Wait for event completion from PRU */
       prussdrv_pru_wait_event (PRU_EVTOUT_0);  // This assumes the PRU generates an interrupt 
                                                // connected to event out 0 immediately before halting
   
       /* Disable PRU and close memory mappings */
       prussdrv_pru_disable(PRU_NUM); 
       prussdrv_exit ();
    }
```