/*------------------------------------
-- Fancy that, a CC65 NES-Dev helping header!
-- Provides a lot of constants needed
-- to simplify the whole NES development
-- process. This thing is REALLY complex,
-- after all! Please enjoy.

-- * Your boy, Jack
-------------------------------------*/
#include "neslib.h"
#include "nesdev.h"
#include <stdlib.h>

/*
  Fun utilities
*/
void __fastcall__ flash (const u8 *normal_palette, const u8 *flash_palette)
{
  static u8 flashing = 0;
	flashing ^= 1;
	pal_bg(flashing ? flash_palette : normal_palette);
}

void __fastcall__ shake (s8 force)
{
  static u8 scroll_x = 0;
  static u8 scroll_y = 0;
  scroll_x = rand8() % force;
	scroll_y = rand8() % force;
	if (rand8() > 128)
		scroll_x *= -1;
	if (rand8() > 128)
    scroll_y *= -1;
  scroll(scroll_x, scroll_y);
}

/*
    Draw functions
*/
void __fastcall__ spr (u8 tile, u8 x, u8 y, u8 attr, u8 *oam_ptr)
{
  *oam_ptr = oam_spr(x, y, tile, attr, *oam_ptr);
}

void __fastcall__ metaspr (const u8 * tile_buffer, u8 x, u8 y, u8 *oam_ptr)
{
  *oam_ptr = oam_meta_spr(x, y, *oam_ptr, tile_buffer);
}

void __fastcall__ spr_s (const sprite_t *sprite, u8 *oam_ptr)
{
    *oam_ptr = oam_spr(sprite->x, 
                       sprite->y, 
                       sprite->tile_index, 
                       0, 
                       *oam_ptr);
}

void __fastcall__ metaspr_s (const metasprite_t *metasprite, u8 *oam_ptr)
{
    *oam_ptr = oam_meta_spr(metasprite->x, 
                            metasprite->y, 
                            *oam_ptr, 
                            metasprite->index_buffer);
}

/*
    Rectangle functions
*/
static u8 rect_max_x1, // Helps calculate collisions more easily
          rect_max_x2, 
          rect_max_y1, 
          rect_max_y2;

u8 __fastcall__ point_in_rect (const rect_t *rect, u8 x, u8 y)
{
  rect_max_x1 = rect->x + rect->w;
  rect_max_y1 = rect->y + rect->h;
  return (x > rect->x && y > rect->y && x < rect_max_x1 && y < rect_max_y1);
}

u8 __fastcall__ rect_collides(const rect_t *first, const rect_t *second)
{
  rect_max_x1 = first->x + first->w;
  rect_max_y1 = first->y + first->h;
  rect_max_x2 = second->x + second->w;
  rect_max_y2 = second->y + second->h;
  return (first->x < rect_max_x2 && 
          rect_max_x1 > second->x &&
          first->y < rect_max_y2 && 
          rect_max_y1 > second->y);
}

/*
    Digit system
*/
void __fastcall__ digit_update(digits_t *digits)
{
  static u8 i = 0;
  
  // If a digit is over 9, ground it and set the next one up
  for (i = 0; i < 6; ++i)
  {
    if (digits->segments[i] > 9)
    {
      digits->segments[i]    = 0;
      digits->segments[i+1] += 1;
    }
  }

  // Cap last digit at 9
  if (digits->segments[7] > 9)
    digits->segments[7] = 9;
}

void __fastcall__ digit_increment(digits_t *digits, s8 amt)
{
  digits->segments[0] += amt;
  digit_update(digits);
}

void __fastcall__ nt_print(u16 adr, const u8* str)
{
	vram_adr(adr);
	while(1)
	{
		if (!(*str)) break;
		vram_put((*str++)+ASCII_OFFSET);
	}
}