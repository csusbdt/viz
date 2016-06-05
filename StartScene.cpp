#include "SDL.h"
#include "global.h"
#include "StartScene.h"
#include "Disk.h"
#include "App.h"

using namespace std;

StartScene::StartScene() 
: disk(1, .2, .5, .5, 0, 0, 0) {
}

StartScene::~StartScene() {
}

void StartScene::start() {
	disk.setP(1.0);
	disk.setHue(180);
	app.addDrawable(&disk);
	app.addUpdatable(&disk);
}

void StartScene::stop() {
}

bool StartScene::processEventQueue(SDL_Event * e) {
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_a) log("a pressed");
		else if (e->key.keysym.sym == SDLK_w) log("w pressed"); 
	}
	return true;
}

void StartScene::update(Uint32 deltaMillis) {
}

