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
	app.addUpdatable(&disk);
}

void BreathScene::stop() {
	app.clearDrawables();
	app.clearUpdatables();
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
}

