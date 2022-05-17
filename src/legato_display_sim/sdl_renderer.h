#ifndef __SDL_RENDERER_H__
#define __SDL_RENDERER_H__

#include "definitions.h"

#define SDL_HOR_RES             800
#define SDL_VER_RES             480
#define SDL_BYTES_PER_PIXEL     2

void sdl_renderer_init(void);
void sdl_renderer_update (void);
void sdl_test(void);

#endif
