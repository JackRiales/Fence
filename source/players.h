#ifndef _PLAYERS_H_
/*===================================================================
== FENCE
== A Game for the Nintendo Entertainment System ... in 2017
== Written by Jack Riales using CC65 and heavy use of
== SHIRU's Neslib C library (Thanks you gosh dang hero).
===================================================================*/
#define _PLAYERS_H_

#include "nesdev.h"

// Player States
#define PLAYERSTATE_IDLE  1<<0
#define PLAYERSTATE_RUN   1<<1
#define PLAYERSTATE_STAB  1<<2
#define PLAYERSTATE_JUMP  1<<3
#define PLAYERSTATE_HIT   1<<4

// Sword states
#define SWORDSTATE_UP     1<<5
#define SWORDSTATE_CENTER 1<<6
#define SWORDSTATE_DOWN   1<<7

#define NUM_PLAYERS   2
#define PLAYER_HEIGHT 16 // In pixels

typedef struct player
{
    u8            x;
    u8            y;
    u8            state;
    metasprite_t *sprite;
    rect_t        body;
    rect_t        hitbox;
} player_t;

// Constant data
extern const u8 META_PLAYERONE[];

// Initializes player data with default data
void __fastcall__ player_init   (player_t *player);

// Updates player state
void __fastcall__ player_update (player_t *player);

// Moves a player and keeps boxes consistent
void __fastcall__ player_move   (player_t *player, s8 dx, s8 dy);

// Draws the player assuming it's been assigned a sprite
void __fastcall__ player_draw   (player_t *player, u8 *oam_ptr);

#endif