#include <iostream>
#include "SDL.h"
#include "global.h"
#include "App.h"
#include "Util.h"
#include "StartScene.h"
#include "BreathScene.h"

using namespace std;

App::App() : 
	running(true), 
	millisPerUpdate(1000/60.0),
	maxJump(40),
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
	srand(time(0));
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

	clearScreen();

	startScene = new StartScene();
	breathScene = new BreathScene();

	scene = startScene;
	scene->start();
}

/*
	Loop until either processEventQueue returns false
	or running gets set to false.  Pad each pass through 
	the main loop with a delay to achieve the desired 
	millisPerUpdate.
*/
void App::loop() {
	Uint32 previousMillis = millis;
	while (running) {
		previousMillis = millis;
		millis = SDL_GetTicks();
		Uint32 elapsedTime = millis - previousMillis;
		if (!processEventQueue()) break;
		update(elapsedTime);
		draw();
		if (elapsedTime < millisPerUpdate) {
			SDL_Delay(millisPerUpdate - elapsedTime);
			if (maxJump > 4) --maxJump;
		} else {
			if (maxJump < 5000) ++maxJump;
			SDL_Delay(1);
		}
	}
}

void App::update(Uint32 deltaMillis) {
	scene->update(deltaMillis);
}

void App::clearScreen() {
	double saveP = cover.getP();
	cover.setP(1.0);
	for (int i = 0; i < surface->w; ++i) {
		for (int j = 0; j < surface->h; ++j) {
			cover.draw(i, j);
		}
	}
	cover.setP(saveP);
}

void App::draw() {
	int n = -1;
	int max = surface->w * surface->h;
	while (n < max) {
		n += Util::randomInt(1, maxJump);
		int i = n / surface->h;
		int j = n - i * surface->h;
		for (int k = 0; k < drawables.size(); ++k) {
			if (drawables[k]->draw(i, j)) break;
		}
	}
	if(SDL_UpdateWindowSurface(window) != 0) {
		fatal(SDL_GetError());
	}
}

void App::draw(int i, int j, char r, char g, char b) const {
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawPoint(renderer, i, j);
}

int App::dPixels(double d) const {
	return surface->h * d;
}

int App::xPixels(double x) const {
	return surface->w * x;
}

int App::yPixels(double y) const {
	return surface->h * y;
}

void App::addDrawable(Drawable * drawable) {
	drawables.push_back(drawable);
}

bool App::processEventQueue() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		} else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
			return false;
		} else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f) {
			toggleFullscreen();
		} else {
			return scene->processEventQueue(&e);
		}
	}
	return true;
}

void App::shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::createRenderer() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		SDL_FreeSurface(surface);
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
	scene->stop();
	scene->start();
	clearScreen();
}

