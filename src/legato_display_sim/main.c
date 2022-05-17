#include <emscripten.h>
#include "definitions.h"
#include "sdl_input.h"
#include "sdl_renderer.h"

static void main_loop(void *arg)
{
    sdl_input_update();
    Legato_Tasks();
    sdl_renderer_update();
}

int main(int argc, char **argv)
{
    sdl_renderer_init();
    Legato_Initialize();
    emscripten_set_main_loop_arg(main_loop, NULL, -1, true);
}
