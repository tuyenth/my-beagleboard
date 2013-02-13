/*
 * SPI testing utility (using spidev driver)
 *
 * Copyright (c) 2007  MontaVista Software, Inc.
 * Copyright (c) 2007  Anton Vorontsov <avorontsov@ru.mvista.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define SMP64  0x40
#define SMP128 0x80
#define POT_MS 100

static const char *device = "/dev/spidev1.1";
static uint8_t resolution = 16;
static uint8_t sampling = SMP64;
static uint16_t speed = 48000;

static void configure_shit(void)
{
	return;
}

static void wait_wdclk_rise(void) 
{
	return;
}

static void wait_wdclk_fall(void) 
{
	return;
}

static void wait_bclk_rise(void) 
{
	return;
}

static void adat_rx_tx_odd(uint8_t bit) 
{
	return;
}

static void adat_rx_tx_even(uint8_t bit) 
{
	return;
}

static void mix() 
{
	return;
}

static void read_pots(void)
{
	return;
}

int main(int argc, char *argv[])
{
	int i = 0; 
	int j = 0;
	int bit = 0;
	int potPeriod = speed * POT_MS / 1000; 
	
	configure_shit();
	read_pots();
	wait_wdclk_fall(); // to sync
	
	while(1)
	{
		if (i >= potPeriod)
		{
			read_pots();
			i=0;
		}
		
		for (j = 0 ; j < sampling ; ++j, ++i)
		{
			wait_wdclk_rise(); // odd channels
			
			for (bit = 0 ; bit < resolution ; ++bit)
			{
				adat_rx_tx_odd(bit);
				wait_bclk_rise();
			}
			mix_odd(); // (32 - resolution)/(speed*64) time to act
			
			wait_wdclk_fall(); // even channels

			for (bit = 0 ; bit < resolution ; ++bit)
			{
				adat_rx_tx_even(bit);
				wait_bclk_rise();
			}
			mix_even(); // (32 - resolution)/(speed*64) time to act
		}
	}

	return 0;
}
