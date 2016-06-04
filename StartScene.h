#pragma once

#include "Scene.h"
#include "Disk.h"

class StartScene : public Scene {
	public:
		StartScene();
		virtual ~StartScene();
                virtual void init();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);
	private:
		Disk disk;
};

