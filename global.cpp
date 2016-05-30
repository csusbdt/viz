#include <cassert>
#include "global.h"

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

void create_renderer() {
	surface = SDL_GetWindowSurface(window);
	if (!surface) fatal(SDL_GetError());
	renderer = SDL_CreateSoftwareRenderer(surface);
	if (!renderer) fatal(SDL_GetError());
}

void toggle_fullscreen() {
	bool fullscreen = SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (fullscreen) {
		if (SDL_SetWindowFullscreen(window, 0)) {
			fatal(SDL_GetError());
		}
	} else {
		if (SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP)) {
			fatal(SDL_GetError());
		}
	}
	create_renderer();
}

