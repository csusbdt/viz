#include <cassert>
#include <iostream>
#include "global.h"

StartScene * startScene = 0;
BreathScene * breathScene = 0;

void fatal(const char * fmt, ...) {
	va_list v;
	char buf[1024];

	va_start(v, fmt);
	vsnprintf(buf, 1024, fmt, v);
	va_end(v);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Viz", buf, NULL);
	exit(1);
}

void log(const char * msg) {
	std::cout << msg << std::endl;
}

