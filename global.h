#pragma once

#include <iostream>
#include "SDL.h"

extern SDL_Window   * window;
extern SDL_Surface  * surface;
extern SDL_Renderer * renderer;
void create_renderer();
void toggle_fullscreen();

void fatal(const char * fmt, ...);


