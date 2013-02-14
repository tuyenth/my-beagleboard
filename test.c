/*
 * ADAT mixer driver 
 *
 * Copyright (c) 2013  Daniel Lopez-Arozena <dlopezaro@gmail.com>
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
#define FS48K 48000
#define FS44K 441000
#define HIGH 1
#define LOW  0

static const char *device = "/dev/spidev1.1";
static uint8_t wdclk = LOW;       // Fs Clock. (48KHz, 44.1KHz)
static uint8_t bclk = LOW;        // Data Clock (64 * Fs = 3072KHz, 2822.4KHz)
static uint8_t resolution = 16;   // sample data resolution (16, 24 bits)
static uint8_t sampling = SMP64;  // Number of samples buffer (64, 128)
static uint16_t fs = FS48K;    // Sampling Frequency (Fs) in Hz (48000KHz, 44.1KHz)

static void configure_shit(void)
{
//    wake_up_interruptible(&short_queue); /* awake any reading process */

	return;
}

static void wait_wdclk_rise(void) 
{
  if (wdclk == LOW)
    wait_event_interruptible(wdclk_queue, wdclk == HIGH);
	return;
}

static void wait_wdclk_fall(void) 
{
  if (wdclk == HIGH)
    wait_event_interruptible(wdclk_queue, wdclk == LOW);
	return;
}

static void wait_bclk_rise(void) 
{
  if (bclk == LOW)
    wait_event_interruptible(bclk_queue, bclk == HIGH);

  bclk = LOW;
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

static void mix_odd() 
{
	return;
}

static void mix_even() 
{
	return;
}

static void read_pots(void)
{
	return;
}

static void adat_io(sampling, resolution)
{
	unsigned short n = 0;
	unsigned short bit = 0;

  for (n = 0 ; n < sampling ; ++n)
  {
    wait_wdclk_rise(); // odd channels
    
    for (bit = 0 ; bit < resolution ; ++bit)
    {
      wait_bclk_rise();
      adat_rx_tx_odd(bit);
    }
    /*  
        Time to mix = (32 - resolution)/(fs*64)
        For 16 and 48000 Hz, T = 5,2 us
        For 16 and 44100 Hz, T = 5,6 us
    */
    
    wait_wdclk_fall(); // even channels

    for (bit = 0 ; bit < resolution ; ++bit)
    {
      wait_bclk_rise();
      adat_rx_tx_even(bit);
    }
  }
}

int main(int argc, char *argv[])
{
	unsigned short t = 1; 
	unsigned short n = 0;
	unsigned short bit = 0;
	unsigned short potPeriod = fs * POT_MS / 1000; 
	
	configure_shit();
	
  wait_wdclk_fall(); // to sync
	
	while(1)
	{
		if (read_pots(&t))
			t = potPeriod;
      
    adat_io(sampling, resolution);  

    mix_data(); // Launch thread to mix. Takes sampling time?
  }
	return 0;
}

