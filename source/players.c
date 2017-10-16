/*===================================================================
== FENCE
== A Game for the Nintendo Entertainment System ... in 2017
== Written by Jack Riales using CC65 and heavy use of
== SHIRU's Neslib C library (Thanks you gosh dang hero).
===================================================================*/
#include "players.h"

static u8 i; // Local module iterator

// Default player metasprite
const u8 META_PLAYERONE[] =
{
    6,  0, 0x50, 0, // Body
    6,  8, 0x60, 0,
    14, 4, 0x40, 0, // Sword
    22, 4, 0x41, 0,
    2,  0, 0x51, 0, // Stretched hand
	METASPR_EOB /* End of buffer */
};

