/*===================================================================
== FENCE
== A Game for the Nintendo Entertainment System ... in 2017
== Written by Jack Riales using CC65 and heavy use of
== SHIRU's Neslib C library (Thanks you gosh dang hero).
===================================================================*/

/* Headers */
#define TV_NTSC 1
#define ENABLE_INTRO 1
#include <stddef.h>
#include <stdlib.h>
#include "neslib.h"
#include "nesdev.h"
#include "players.h"

/* Data inclusions */
#include "gamedata.c"
#include "test_map.h"

/* Initialize nametables here (pre-ppu state) */
void nt_init (void)
{
	// Draw map
	vram_adr(NAMETABLE_A);
	vram_unrle(test_map);
}

/* Initialize game state here (post-ppu state) */
void init (void)
{
	// Setup player data
	for (i = 0; i < NUM_PLAYERS; ++i)
	{
		player_sprites[i].index_buffer = (u8*) META_PLAYERONE;
		player_init(&players[i]);
		players[i].sprite = &player_sprites[i];
	}
}

/* Update game state */
void update (void)
{
	// Input processing
	pads[0] = pad_poll(0);
	pads[1] = pad_poll(1);

	// Flash the screen 
	if (flash_time > 0)
	{
		flash(BG_PALETTES, BG_PALETTES_FLASH);
		-- flash_time;
	}
	else
		pal_bg(BG_PALETTES);

	// Shake the screen
	if (shake_time > 0)
	{
		shake(shake_force);
		-- shake_time;
	}
	else
	{
		scroll_x = 0;
		scroll_y = 0;
		scroll(scroll_x, scroll_y);
	}
}

/* Uses the OAM to draw our sprites */
void draw (void)
{
	player_draw(&players[0], &oam_ptr);
	player_draw(&players[1], &oam_ptr);
}

void main (void)
{
	pal_bg(BG_PALETTES);
	pal_spr(SPRITE_PALETTES);

	nt_init();
	ppu_on_all();
	
	init();
	
	while(1)
	{
		ppu_wait_nmi();
		
		// Main update
		update();

		// OAM draw
		oam_ptr = 0;
		draw();
		
		// Count frames
		++frame;
	}
}
