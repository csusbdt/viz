/*
This program avoids double buffering; there is only one drawing surface.
X-Y positions are given as percentages of window width and height.
Distances are given as percentages of window height.
*/

#include <iostream>
#include <vector>
#include "SDL.h"
#include "global.h"
#include "Cover.h"
#include "Disk.h"

using namespace std;

SDL_DisplayMode display;
SDL_Window   * window   = nullptr;
SDL_Surface  * surface  = nullptr;
SDL_Renderer * renderer = nullptr;
bool running = true;
vector<Drawable *> drawables;
vector<Updatable *> updatables;
Uint32 millis = 0;

static int millis_per_update = 1000 / 60;
static Cover * cover = nullptr;
static Disk  * disk  = nullptr;

void init();
void loop();
void shutdown();
void update(int deltaMillis);
void draw();
bool process_event_queue();

int main(int argc, char * argv[]) {
	init();
	loop();
	shutdown();
	return 0;
}

void init() {
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		fatal(SDL_GetError());
	}

	SDL_ShowCursor(SDL_DISABLE);

	if (SDL_GetCurrentDisplayMode(0, &display) != 0) {
		fatal(SDL_GetError());
	}

	window = SDL_CreateWindow(
		"Viz", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		display.w, 
		display.h, 
		0);
	if (!window) fatal(SDL_GetError());

	create_renderer();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	cover = new Cover();
	cover->prob = 1.0;
	drawables.push_back(cover);

	draw();

	cover->prob = 0.008;

	disk = new Disk();
	disk->prob = 1.0;
	disk->setHue(180);
	drawables.push_back(disk);
	updatables.push_back(disk);
}

/*
	Loop until either process_event_queue returns false
	or running gets set to false.  Pad each pass through 
	the main loop with a delay to achieve the desired 
	millis_per_update.
*/
void loop() {
	while (running) {
		millis = SDL_GetTicks();
		if (!process_event_queue()) break;
		update(millis_per_update);
		draw();
		Uint32 elapsed_time = SDL_GetTicks() - millis;
		if (elapsed_time < millis_per_update) {
			SDL_Delay(millis_per_update - elapsed_time);
		} else {
			SDL_Delay(1);
		}
	}
}

void update(int deltaMillis) {
	for (int i = 0; i < updatables.size(); ++i) {
		updatables[i]->update(deltaMillis);
	}
}

void draw() {
	for (int i = 0; i < surface->w; ++i) {
		for (int j = 0; j < surface->h; ++j) {
			for (int k = 0; k < drawables.size(); ++k) {
				if (drawables[k]->draw(i, j)) break;
			}
		}
	}
	if(SDL_UpdateWindowSurface(window) != 0) {
		fatal(SDL_GetError());
	}
}

bool process_event_queue() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) return false;
			else if (e.key.keysym.sym == SDLK_f) toggle_fullscreen(); 
		} else if (e.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

