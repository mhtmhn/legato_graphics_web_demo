#include <emscripten.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "sdl_input.h"
#include "sdl_renderer.h"

static void main_loop(void *arg)
{
    sdl_input_update();
    sdl_test();
    sdl_renderer_update();
}

int main(int argc, char **argv)
{
    sdl_renderer_init();
    emscripten_set_main_loop_arg(main_loop, NULL, -1, true);
}
