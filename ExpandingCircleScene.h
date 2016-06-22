#pragma once

#include "Scene.h"
#include "ExpandingCircle.h"
#include <vector>

using namespace std;

class ExpandingCircleScene : public Scene {
	public:
		ExpandingCircleScene();
		virtual ~ExpandingCircleScene();
                virtual void start();
                virtual void stop();
		virtual void update(Uint32 dt);
                virtual bool processEventQueue(SDL_Event * e);

	private:
		vector<ExpandingCircle> circles;
};

