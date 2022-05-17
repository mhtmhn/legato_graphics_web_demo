#include "sdl_input.h"
#include <SDL2/SDL.h>

static SDL_Event event;

static void sdl_mouse_input_handler(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_MOUSEBUTTONUP:
        if (event->button.button == SDL_BUTTON_LEFT)

            break;
    case SDL_MOUSEBUTTONDOWN:
        if (event->button.button == SDL_BUTTON_LEFT)
        {
        }
        break;
    case SDL_MOUSEMOTION:

        break;
    case SDL_FINGERUP:

        break;
    case SDL_FINGERDOWN:

        break;
    case SDL_FINGERMOTION:

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
