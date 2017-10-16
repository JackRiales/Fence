/*===================================================================
== FENCE
== A Game for the Nintendo Entertainment System ... in 2017
== Written by Jack Riales using CC65 and heavy use of
== SHIRU's Neslib C library (Thanks you gosh dang hero).
===================================================================*/
#include "nesdev.h"
#include "players.h"

/* Zero-page Globals (commonly used vars) */
#pragma bss-name(push, "ZEROPAGE")
/* Often used vars */
u8 i;               /* Iterator */
u8 j;               /* Iterator */
u8 frame;           /* Frame counter */

/* Input state */
u8 pads [2];

/* Current sprite oam offset */
u8 oam_ptr;

/* Player data */
player_t players [NUM_PLAYERS];

/* Brightness values */
u8 bg_bright = 4;
u8 spr_bright = 4;
u8 flash_time = 0;

/* Scrolls */
s8 scroll_x = 0;
s8 scroll_y = 0;
u8 shake_time = 0;
u8 shake_force = 10;
#pragma bss-name(pop)

/* Palettes */
const unsigned char BG_PALETTES[16]=
{ 
	0x00,0x0f,0x10,0x30,
	0x00,0x01,0x21,0x31,
	0x00,0x06,0x16,0x26,
	0x00,0x09,0x19,0x29
};

const u8 BG_PALETTES_FLASH[16] =
{
	0x30, 0x00, 0x10, 0x20,
	0x30, 0x00, 0x10, 0x20,
	0x30, 0x00, 0x10, 0x20,
	0x30, 0x00, 0x10, 0x20
};

const u8 SPRITE_PALETTES[16] =
{
	0x0f,0x17,0x27,0x37,
	0x0f,0x11,0x21,0x31,
	0x0f,0x15,0x25,0x35,
	0x0f,0x19,0x29,0x39
};