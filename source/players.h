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
#define PLAYERSTATE_IDLE 0
#define PLAYERSTATE_RUN  1
#define PLAYERSTATE_STAB 2
#define PLAYERSTATE_JUMP 3

// Sword states
#define SWORDSTATE_UP     0
#define SWORDSTATE_CENTER 1
#define SWORDSTATE_DOWN   2

// Player data definition (Struct-of-arrays style for speed)
#define NUM_PLAYERS 2 // 2-player game

typedef struct player
{
    u8           state;
    metasprite_t sprite;
    rect_t       body;
    rect_t       hitbox;
} player_t;

typedef struct sword
{
    u8           state;
    metasprite_t sprite;

} sword_t;

// Constant data
extern const u8 META_PLAYERONE[];


#endif