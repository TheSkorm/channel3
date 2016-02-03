//Copyright 2016 <>< Charles Lohr, See LICENSE file.

#ifndef _NTSC_BROADCAST_TEST
#define _NTSC_BROADCAST_TEST

/*
	This is the NTSC Broadcast code.  To set it up, call testi2s_init.
	This will set up the DMA engine and all the chains for outputting 
	broadcast.

	This is tightly based off of SpriteTM's ESP8266 MP3 Decoder.

	If you change the RF Maps, please call redo_maps, this will make
	the system update all the non-frame data to use the right bit patterns.
*/


//Stuff that should be for the header:

#include <c_types.h>

//Framebuffer width/height
#define FBW 256 //Must be divisible by 8.  These are actually "double-pixels" used for double-resolution monochrome width.
#define FBW2 (FBW/2) //Actual width in true pixels.
#define FBH 232

#define DMABUFFERDEPTH 5

extern int gframe; //Current frame #
extern uint8_t framebuffer[((FBW2/2)*(FBH))*2]; // /2 = two pixels per byte (*2 = double buffer)


void ICACHE_FLASH_ATTR testi2s_init();
void ICACHE_FLASH_ATTR redo_maps();

#endif

