#pragma once

/*
This program avoids double buffering; there is only one drawing surface.
X-Y positions are given as percentages of window width and height.
Distances are given as percentages of window height.
*/

#include <vector>
#include "SDL.h"
#include "Cover.h"
#include "Scene.h"
#include "Drawable.h"
#include "Updatable.h"

using namespace std;

class App {
	public:
		App();
		void run();
		int dPixels(double d) const;  // arg d (for distance) is percent of screen height
		int xPixels(double x) const;  // arg y is percent of screen width
		int yPixels(double y) const;  // arg x is percent of screen height
		void draw(int i, int j, char r, char g, char b) const;
		void addDrawable(Drawable * drawable);
		void addUpdatable(Updatable * updatable);
		void clearDrawables() { drawables.clear(); }
		void clearUpdatables() { updatables.clear(); }

		Cover cover;
		Uint32 millis;  // Total elapsed time in millis.
		Scene * scene;

	private:
		void init();
		void loop();
		void shutdown();
		void draw();
		void clearScreen();
		void update(Uint32 deltaMillis);
		bool processEventQueue();
		void toggleFullscreen();
		void createRenderer();

		vector<Drawable *>  drawables;
		vector<Updatable *> updatables;

		bool                running;
		Uint32              millisPerUpdate;
		int                 maxJump;
		SDL_DisplayMode     display;
		SDL_Window *        window;
		SDL_Surface *       surface;
		SDL_Renderer *      renderer;
};

