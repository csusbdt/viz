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
#include "FallingCirclesScene.h"
#include "BreathScene.h"
#include "ExpandingCirclesScene.h"

using namespace std;

class App {
	public:
		App();
		void run();

		int dPixels(double d) const;  // arg d (for distance) is percent of screen height
		int xPixels(double x) const;  // arg y is percent of screen width
		int yPixels(double y) const;  // arg x is percent of screen height
		double pixelToY(double d) const; // convert distance in pixels to percent of screen height
		void draw(int i, int j, char r, char g, char b) const;
		void addDrawable(Drawable * drawable);
		void clearDrawables() { drawables.clear(); }

		Uint32 millis;  // Total elapsed time in millis.
		Scene * scene;
		bool running;
		Cover cover;
		FallingCirclesScene fallingCirclesScene;
		BreathScene breathScene;
		ExpandingCirclesScene expandingCirclesScene;

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

		Uint32              millisPerUpdate;
		int                 maxJump;
		int                 millisToSceneChange;
		SDL_DisplayMode     display;
		SDL_Window *        window;
		SDL_Surface *       surface;
		SDL_Renderer *      renderer;
};

