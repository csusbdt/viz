#pragma once

#include "SDL.h"

class Scene {
	public:
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void update(Uint32 dt) = 0;
		virtual bool processEventQueue(SDL_Event * e) = 0;

	protected:
		virtual ~Scene() {}
};

