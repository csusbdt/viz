#pragma once

#include <cassert>
#include "SDL.h"
#include "App.h"
#include "StartScene.h"
#include "BreathScene.h"

extern App app;
extern StartScene * startScene;
extern BreathScene * breathScene;

void fatal(const char * fmt, ...);
void log(const char * msg);


