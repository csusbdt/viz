#pragma once

#include "Scene.h"
#include "StartDisk.h"
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
	private:
		vector<StartDisk> disks;
};

