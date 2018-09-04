/*	example code for cc65, for NES
 *  test fading in and out (w full screen image)
 *	using neslib
 *	Doug Fraker 2018
 */	
 


#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "NES_ST/Girl3.h"



const unsigned char palette[]={
0x0f, 0x17, 0x27, 0x36,
0,0,0,0,
0,0,0,0,
0,0,0,0
}; 




	

void main (void) {
	
	ppu_off(); // screen off

	pal_bg(palette); //	load the palette
	
	vram_adr(NAMETABLE_A);
	// this sets a start position on the BG, top left of screen
	
	vram_unrle(Girl3);
	// this unpacks a compressed full nametable
	
	pal_bright(0);	// can be a value 0 (black) to 8 (white), 4 = normal
					// the init code set it to 4 by default
	
	ppu_on_all(); // turn on screen
	
	delay(10); // wait 10 frames
	
	while (1){
		
		pal_fade_to(0,4); // (from, to) fade in to normal
		
		delay(100); // wait 100 frames
	
		pal_fade_to(4,0); // (from, to) fade to black
		
		delay(100); // wait 100 frames
		
	}
}
	
	