#include "SDL.h"
#include "global.h"
#include "BreathScene.h"
#include "StartScene.h"
#include "App.h"

using namespace std;

BreathScene::BreathScene() { 
}

BreathScene::~BreathScene() {
}

void BreathScene::start() {
	app.addDrawable(&disk);
}

void BreathScene::stop() {
	app.clearDrawables();
}

bool BreathScene::processEventQueue(SDL_Event * e) {
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_x) log("x pressed");
		else if (e->key.keysym.sym == SDLK_n) {
			this->stop();
			startScene->start();
			app.scene = startScene;
		}
	}
	return true;
}

void BreathScene::update(Uint32 deltaMillis) {
	disk.update(deltaMillis);
}

