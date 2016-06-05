#pragma once

class Scene {
	public:
		virtual ~Scene() {}
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void update(Uint32 dt) = 0;
		virtual bool processEventQueue(SDL_Event * e) = 0;
};

