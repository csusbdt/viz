#include "SDL.h"
#include "global.h"
#include "FallingCirclesScene.h"
#include "StartDisk.h"
#include "App.h"
#include "BreathScene.h"
#include <iostream>

using namespace std;

FallingCirclesScene::FallingCirclesScene() { 
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
	disks.push_back(StartDisk());
}

FallingCirclesScene::~FallingCirclesScene() {
}

void FallingCirclesScene::start() {
	app.cover.setP(0.15);
	app.addDrawable(&app.cover);
	for (int i = 0; i < disks.size(); ++i) {
		disks[i].reset();
		app.addDrawable(&disks[i]);
	}
}

void FallingCirclesScene::stop() {
	app.clearDrawables();
}

bool FallingCirclesScene::processEventQueue(SDL_Event * e) {
	//if (e->type == SDL_KEYDOWN) {
	//	if (e->key.keysym.sym == SDLK_a) log("a pressed");
	//	else if (e->key.keysym.sym == SDLK_w) log("w pressed"); 
	//	else if (e->key.keysym.sym == SDLK_n) {
	//		stop();
	//		app.breathScene.start();
	//		app.scene = &app.breathScene;
	//	}
	//}
	return true;
}

void FallingCirclesScene::update(Uint32 deltaMillis) {
	for (int i = 0; i < disks.size(); ++i) {
		disks[i].update(deltaMillis);
	}
}

