#include "SDL.h"
#include "global.h"
#include "StartScene.h"
#include "StartDisk.h"
#include "App.h"
#include "BreathScene.h"
#include <iostream>

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
	app.cover.setP(0.15);
	app.addDrawable(&app.cover);
	for (int i = 0; i < disks.size(); ++i) {
		disks[i].reset();
		app.addDrawable(&disks[i]);
	}
}

void StartScene::stop() {
	app.clearDrawables();
}

bool StartScene::processEventQueue(SDL_Event * e) {
	if (e->type == SDL_KEYDOWN) {
		if (e->key.keysym.sym == SDLK_a) log("a pressed");
		else if (e->key.keysym.sym == SDLK_w) log("w pressed"); 
		else if (e->key.keysym.sym == SDLK_n) {
			stop();
			app.breathScene.start();
			app.scene = &app.breathScene;
		}
	}
	return true;
}

void StartScene::update(Uint32 deltaMillis) {
	for (int i = 0; i < disks.size(); ++i) {
		disks[i].update(deltaMillis);
	}
}

