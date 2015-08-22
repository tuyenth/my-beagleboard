Communication between various elements of the PRUSS or the wider SoC may take place either directly, over a bus, via interrupts or via DMA.

The following lists will expose all possible communication approaches for each likely scenario.

For communication via interrupts, please first read the section on the [PRUSSv2 Interrupt Controller](http://elinux.org/PRUSSv2_Interrupt_Controller).

[Click here for a full list of PRUSS Interrupts.](http://elinux.org/PRUSSv2_Interrupts)

The current [example PRU loader](https://github.com/beagleboard/am335x_pru_package/blob/master/pru_sw/app_loader/interface/prussdrv.c) uses [UIO](http://arago-project.org/git/projects/?p=linux-am33x.git;a=commit;h=f1a304e7941cc76353363a139cbb6a4b1ca7c737), but this ideally should be replaced with [remoteproc](http://omappedia.org/wiki/Category:RPMsg) rather than poking at the registers from userspace. In the mean time, according to [this discussion:](https://groups.google.com/d/msg/beagleboard/gqCjxh4uZi0/_uIUD8ZF88QJ) we can use the included script and load the uio\_pruss userspace driver.

## PRU to Host (PRU to ARM Cortex-A8) ##
Include the uio\_pruss kernel driver by using modprobe uio\_pruss or the steps outlined above, if that does not work. Then in a project include the header files for the am335x\_pru\_package.
```
   #define PRU_NUM0	  0
   // Driver header file
   #include <prussdrv.h>
   #include <pruss_intc_mapping.h>	 

/* Then, initialize the interrupt controller data */
   tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

/* Initialize the PRU */
   prussdrv_init ();

/* Get the interrupt initialized */
   prussdrv_pruintc_init(&pruss_intc_initdata)

/* Execute example on PRU0 where first argument is the PRU# and second is the assembly to execute*/
   prussdrv_exec_program (PRU_NUM0, "./example.bin");

/* Wait until PRU0 sends the interrupt*/
   prussdrv_pru_wait_event (PRU_EVTOUT_0);

/* Clear the interrupt*/
   prussdrv_pru_clear_event (PRU0_ARM_INTERRUPT);
```

The PRU (in this case 0) will have the following in the example.bin file to trigger the interrupt:

```
   #define PRU0_ARM_INTERRUPT      19
   MOV       r31.b0, PRU0_ARM_INTERRUPT+16
```

Register 31 allows for control of the INTC for the PRU

## Host to PRU (ARM Cortex-A8 to PRU) ##
### Interrupts ###
Each PRU has access to host interrupt channels Host-0 and Host-1 through register [R31](https://code.google.com/p/my-beagleboard/source/detail?r=31) bit 30 and bit 31 respectively.
By probing these registers, a PRU can determine if an interrupt is currently present on each host channel.

To configure


## PRU to external peripherals ##
## External peripherals to PRU ##
## PRU to internal peripherals ##
## Internal peripherals to PRU ##