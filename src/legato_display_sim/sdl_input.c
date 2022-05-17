#include "sdl_input.h"
#include <SDL2/SDL.h>

#define SDL_INPUT_HOR   800
#define SDL_INPUT_VER   480

static SDL_Event event;

static void sdl_mouse_input_handler(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_MOUSEBUTTONUP:
        if (event->button.button == SDL_BUTTON_LEFT)
            leInput_InjectTouchUp(0, event->motion.x, event->motion.y);
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event->button.button == SDL_BUTTON_LEFT)
            leInput_InjectTouchDown(0, event->motion.x, event->motion.y);
        break;
    case SDL_MOUSEMOTION:
        leInput_InjectTouchMoved(0, event->motion.x, event->motion.y);
        break;
    case SDL_FINGERUP:
        leInput_InjectTouchUp(0, event->tfinger.x * SDL_INPUT_HOR, event->tfinger.y * SDL_INPUT_VER);
        break;
    case SDL_FINGERDOWN:
        leInput_InjectTouchDown(0, event->tfinger.x * SDL_INPUT_HOR, event->tfinger.y * SDL_INPUT_VER);
        break;
    case SDL_FINGERMOTION:
        leInput_InjectTouchMoved(0, event->tfinger.x * SDL_INPUT_HOR, event->tfinger.y * SDL_INPUT_VER);
        break;
    }
}

void sdl_input_update(void)
{
    while (SDL_PollEvent(&event))
    {
        sdl_mouse_input_handler(&event);
    }
}
