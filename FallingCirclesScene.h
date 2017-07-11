#pragma once

#include "Scene.h"
#include "StartDisk.h"
#include "BreathScene.h"
#include <vector>

using namespace std;

class FallingCirclesScene : public Scene {
	public:
		FallingCirclesScene();
		virtual ~FallingCirclesScene();
                virtual void start();
                virtual void stop();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);

	private:
		vector<StartDisk> disks;
};

