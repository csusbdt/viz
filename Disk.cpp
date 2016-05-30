#include "Disk.h"
#include "Util.h"
#include "global.h"
#include <cmath>

bool Disk::draw(int i, int j) const {
	double dist = sqrt((surface->w * x - i) * (surface->w * x - i) + (surface->h * y - j) * (surface->h * y - j));
	double p = 0;
	double radiusInPixels = radius * surface->h;
	if (dist < radiusInPixels) p = (radiusInPixels - dist) / radiusInPixels * prob;
	if (Util::randomBool(p)) {
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderDrawPoint(renderer, i, j);
		return true;
	} else {
		return false;
	}
}

void Disk::update(int deltaMillis) {
	double period = 5 * 1000;
	prob = (sin(millis * 2 * 3.14159 / period) + 1) * .5 * .02;
	radius = (sin(millis * 2 * 3.14159 / period) + 1) * .5 * .5;
}

void Disk::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

