#include "sdl_renderer.h"
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint16_t *frame_buffer;

// Legato frame buffer from gfx\driver\controller\lcc\drv_gfx_lcc.c
extern gfxPixelBuffer pixelBuffer;

void sdl_renderer_init(void)
{
    window = SDL_CreateWindow("Legato Graphics Web Demo",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_HOR_RES,
                              SDL_VER_RES,
                              SDL_WINDOW_BORDERLESS);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    texture = SDL_CreateTexture(renderer,
                                SDL_PIXELFORMAT_RGB565,
                                SDL_TEXTUREACCESS_STATIC,
                                SDL_HOR_RES,
                                SDL_VER_RES);

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    frame_buffer = (uint16_t *)malloc(SDL_HOR_RES * SDL_VER_RES * SDL_BYTES_PER_PIXEL);
    memset(frame_buffer, 0xff, SDL_HOR_RES * SDL_VER_RES * SDL_BYTES_PER_PIXEL);
    sdl_renderer_update();

    // Force Legato to use the allocated buffer
    gfxPixelBufferCreate(SDL_HOR_RES,
                         SDL_VER_RES,
                         GFX_COLOR_MODE_RGB_565,
                         frame_buffer,
                         &pixelBuffer);
}

void sdl_renderer_update(void)
{
    SDL_UpdateTexture(texture, NULL, frame_buffer, SDL_HOR_RES * SDL_BYTES_PER_PIXEL);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

typedef struct color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color;

static color hueshift(const color in, float H)
{
    float U = cos(H * M_PI / 180);
    float W = sin(H * M_PI / 180);

    color ret;
    ret.r = (.299 + .701 * U + .168 * W) * in.r + (.587 - .587 * U + .330 * W) * in.g + (.114 - .114 * U - .497 * W) * in.b;
    ret.g = (.299 - .299 * U - .328 * W) * in.r + (.587 + .413 * U + .035 * W) * in.g + (.114 - .114 * U + .292 * W) * in.b;
    ret.b = (.299 - .3 * U + 1.25 * W) * in.r + (.587 - .588 * U - 1.05 * W) * in.g + (.114 + .886 * U - .203 * W) * in.b;
    return ret;
}

// Run this in main_loop to test
void sdl_test(void)
{
    static color test = {0xff, 0x00, 0x00}, out = {0, 0, 0};
    static float angle = 0;
    out = hueshift(test, angle++);
    if (angle == 360)
        angle = 0;
    uint16_t color = (out.r >> 3) << 11 | (out.g >> 2) << 5 | out.b >> 3;
    for (int i = 0; i < SDL_HOR_RES * SDL_VER_RES; i++)
    {
        frame_buffer[i] = color;
    }
    sdl_renderer_update();
    SDL_Delay(5);
}
