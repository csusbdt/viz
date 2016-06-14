#pragma once

#include "Scene.h"
#include "StartDisk.h"
#include "BreathScene.h"
#include <vector>

using namespace std;

class StartScene : public Scene {
	public:
		StartScene();
		virtual ~StartScene();
                virtual void start();
                virtual void stop();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);

		static StartScene instance;

	private:
		vector<StartDisk> disks;
};

