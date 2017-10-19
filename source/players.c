/*===================================================================
== FENCE
== A Game for the Nintendo Entertainment System ... in 2017
== Written by Jack Riales using CC65 and heavy use of
== SHIRU's Neslib C library (Thanks you gosh dang hero).
===================================================================*/
#include "players.h"

// Default player metasprite
const u8 META_PLAYERONE[] =
{
    6,  0, 0x50, 0, // Body
    6,  8, 0x60, 0,
    14, 4, 0x40, 2, // Sword
    22, 4, 0x41, 0,
    2,  0, 0x51, 1, // Stretched hand
	METASPR_EOB /* End of buffer */
};

void __fastcall__ player_init   (player_t *player, u8 id)
{
    player->id = id;
    player->x  = id ? (MAX_X - (MAX_X / 3)) : MAX_X / 3;
    player->y  = 50; // some ground constant for the map
    player->sprite = NULL;
    player->body.w = 8;
    player->body.h = PLAYER_HEIGHT;
    player->hitbox.w = 8;
    player->hitbox.h = PLAYER_HEIGHT;
}

void __fastcall__ player_update (player_t *player)
{

}

void __fastcall__ player_draw (player_t *player, u8 *oam_ptr)
{
    if (! player->sprite) return;
    metaspr(player->sprite->index_buffer, player->x, player->y, oam_ptr);
}