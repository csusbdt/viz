#include "SDL.h"
#include "global.h"
#include "App.h"
#include "StartScene.h"

using namespace std;

App::App() : 
	running(true), 
	millisPerUpdate(1000/60.0),
	window(nullptr),
	surface(nullptr),
	renderer(nullptr),
	scene(nullptr) {
}

void App::run() {
	init();
	loop();
	shutdown();
}

void App::init() {
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

	createRenderer();

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	cover.prob = 1.0;
	draw();
	cover->prob = 0.008;

	scene = new StartScene();
	scene->start();
}

/*
	Loop until either processEventQueue returns false
	or running gets set to false.  Pad each pass through 
	the main loop with a delay to achieve the desired 
	millisPerUpdate.
*/
void App::loop() {
	while (running) {
		millis = SDL_GetTicks();
		if (!processEventQueue()) break;
		update(millisPerUpdate);
		Uint32 elapsed_time = SDL_GetTicks() - millis;
		if (elapsed_time < millis_per_update) {
			SDL_Delay(millis_per_update - elapsed_time);
		} else {
			SDL_Delay(1);
		}
	}
}

void App::update(int deltaMillis) {
	scene->update(deltaMillis);
	for (int i = 0; i < updatables.size(); ++i) {
		updatables[i]->update(deltaMillis);
	}
	draw();
}

void App::draw() {
	if (!cover.draw()) {
		for (int i = 0; i < surface->w; ++i) {
			for (int j = 0; j < surface->h; ++j) {
				for (int k = 0; k < drawables.size(); ++k) {
					if (drawables[k]->draw(i, j)) break;
				}
			}
		}
	}
	if(SDL_UpdateWindowSurface(window) != 0) {
		fatal(SDL_GetError());
	}
}

bool App::processEventQueue() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) return false;
			else if (e.key.keysym.sym == SDLK_f) toggleFullscreen(); 
		} else if (e.type == SDL_QUIT) {
			return false;
		} else return scene->processEventQueue(&e);
	}
	//return true;
}

void App::shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::createRenderer() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		// Not sure if need to destroy window surface.
		// SDL_DestroySurface(surface);
		renderer = nullptr;
		surface  = nullptr;
	}
	surface = SDL_GetWindowSurface(window);
	if (!surface) fatal(SDL_GetError());
	renderer = SDL_CreateSoftwareRenderer(surface);
	if (!renderer) fatal(SDL_GetError());
}

void App::toggleFullscreen() {
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
	createRenderer();
}

