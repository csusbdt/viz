#include "SDL.h"
#include "global.h"
#include "StartScene.h"
#include "Disk.h"

using namespace std;

StartScene::StartScene() : disk() {
}

StartScene::~StartScene() {
}

void StartScene::start() {
	disk.prob = 1.0;
	disk.setHue(180);
	drawables.push_back(&disk);
	updatables.push_back(&disk);
}

void StartScene::stop() {
}

bool StartScene::processEventQueue(SDL_Event * e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_a) cout << "a pressed" << endl;
		else if (e.key.keysym.sym == SDLK_w) cout << "w pressed" << endl; 
	}
	return true;
}

void StartScene::update(Uint32 deltaMillis) {
}

