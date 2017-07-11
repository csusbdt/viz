#pragma once

#include "Scene.h"
#include "ExpandingCircle.h"
#include <vector>

using namespace std;

class ExpandingCirclesScene : public Scene {
	public:
		ExpandingCirclesScene();
		virtual ~ExpandingCirclesScene();
                virtual void start();
                virtual void stop();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);

	private:
		vector<ExpandingCircle> circles;
};

