#progam once

/*
This program avoids double buffering; there is only one drawing surface.
X-Y positions are given as percentages of window width and height.
Distances are given as percentages of window height.
*/

#include <vector>
#include "Cover.h"
#include "Scene.h"
#include "Drawables.h"
#include "Updatables.h"

class App {
	public:
		App();
		void run();

		Cover cover;
		Uint32 millis;

	private:
		void init();
		void loop();
		void shutdown();
		void draw();
		void update(Uint32 deltaMillis);
		bool processEventQueue();
		void toggleFullscreen();
		void createRenderer();

		vector<Drawable *>  drawables;
		vector<Updatable *> updatables;

		bool                running;
		Uint32              millisPerUpdate;
		SDL_DisplayMode     display;
		SDL_Window *        window;
		SDL_Surface *       surface;
		SDL_Renderer *      renderer;
		Scene *             scene;
};

