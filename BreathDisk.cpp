#include "BreathDisk.h"
#include "Util.h"
#include "App.h"
#include "global.h"
#include <cmath>

BreathDisk::BreathDisk() 
: Drawable(1), radius(.5), x(.5), y(.5), r(255), g(255), b(255), dy(0), xPixel(0), yPixel(0), elapsedMillis(0) {
	setHue(30);
	p = 0.10;
}

bool BreathDisk::draw(int i, int j) const {
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

void BreathDisk::update(int deltaMillis) {
	elapsedMillis += deltaMillis;
	xPixel = app.xPixels(x);
	yPixel = app.yPixels(y);
	radius = .2 + .1 * sin(elapsedMillis / 1000.0 * 2 * 3.14159 / 10);
	radiusPixel = app.dPixels(radius);
}

void BreathDisk::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

