#pragma once

#include "SDL.h"
#include "App.h"

extern App app;

void fatal(const char * fmt, ...);
void log(const char * msg);


