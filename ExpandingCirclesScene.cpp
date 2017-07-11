#include "SDL.h"
#include "global.h"
#include "App.h"
#include "ExpandingCircle.h"
#include "ExpandingCirclesScene.h"
#include <iostream>

using namespace std;

ExpandingCirclesScene::ExpandingCirclesScene() { 
	circles.push_back(ExpandingCircle());
	circles.push_back(ExpandingCircle());
	circles.push_back(ExpandingCircle());
	circles.push_back(ExpandingCircle());
	circles.push_back(ExpandingCircle());
	circles.push_back(ExpandingCircle());
}

ExpandingCirclesScene::~ExpandingCirclesScene() {
}

void ExpandingCirclesScene::start() {
	app.cover.setP(0.25);
	app.addDrawable(&app.cover);
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].reset();
		app.addDrawable(&circles[i]);
	}
}

void ExpandingCirclesScene::stop() {
	app.clearDrawables();
}

bool ExpandingCirclesScene::processEventQueue(SDL_Event * e) {
	//if (e->type == SDL_KEYDOWN) {
	//	if (e->key.keysym.sym == SDLK_a) log("a pressed");
	//	else if (e->key.keysym.sym == SDLK_w) log("w pressed"); 
	//	else if (e->key.keysym.sym == SDLK_n) {
	//		stop();
	//		app.startScene.start();
	//		app.scene = &app.startScene;
	//	}
	//}
	return true;
}

void ExpandingCirclesScene::update(Uint32 deltaMillis) {
	for (int i = 0; i < circles.size(); ++i) {
		circles[i].update(deltaMillis);
	}
}

