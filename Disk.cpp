#include "Disk.h"
#include "Util.h"
#include "App.h"
#include "global.h"
#include <cmath>

Disk::Disk(double p, double radius, double x, double y, char r, char g, char b) 
: Drawable(p), radius(radius), x(x), y(y), r(r), g(g), b(b), xPixel(0), yPixel(0) {
}

bool Disk::draw(int i, int j) const {
	double dist = sqrt((xPixel - i) * (xPixel - i) + (yPixel - j) * (yPixel - j));
	double prob = 0;
	if (dist < radiusPixel) prob = (radiusPixel - dist) / radiusPixel * p;
	if (Util::randomBool(prob)) {
		app.draw(i, j, r, g, b);
		return true;
	} else {
		return false;
	}
}

void Disk::update(int deltaMillis) {
	const double period = 5 * 1000;
	p = (sin(app.millis * 2 * 3.14159 / period) + 1) * .5 * .02;
	radius = (sin(app.millis * 2 * 3.14159 / period) + 1) * .5 * .5;
	xPixel = app.xPixels(x);
	yPixel = app.yPixels(y);
	radiusPixel = app.dPixels(radius);
}

void Disk::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

