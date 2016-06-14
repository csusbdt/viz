#pragma once

#include "Scene.h"
#include "BreathDisk.h"

using namespace std;

class BreathScene : public Scene {
	public:
		BreathScene();
		virtual ~BreathScene();
                virtual void start();
                virtual void stop();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);

		static BreathScene instance;

	private:
		BreathDisk disk;
};

