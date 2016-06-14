#include "SDL.h"
#include "global.h"
#include "StartScene.h"
#include "StartDisk.h"
#include "App.h"
#include "BreathScene.h"

using namespace std;

StartScene::StartScene() { 
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
}

StartScene::~StartScene() {
}

void StartScene::start() {
	for (int i = 0; i < disks.size(); ++i) {
		app.addDrawable(&disks[i]);
		app.addUpdatable(&disks[i]);
	}
}

void StartScene::stop() {
	app.clearDrawables();
	app.clearUpdatables();
}

bool StartScene::processEventQueue(SDL_Event * e) {
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_a) log("a pressed");
		else if (e->key.keysym.sym == SDLK_w) log("w pressed"); 
		else if (e->key.keysym.sym == SDLK_n) {
			this->stop();
			breathScene->start();
			app.scene = breathScene;
		}
	}
	return true;
}

void StartScene::update(Uint32 deltaMillis) {
}

