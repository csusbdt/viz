#include "ExpandingDisk.h"
#include "Util.h"
#include "App.h"
#include "global.h"
#include <cmath>

ExpandingDisk::ExpandingDisk() 
: Drawable(1), radius(0), x(0), y(0), r(255), g(255), b(255), dy(0), xPixel(0), yPixel(0), elapsedMillis(0) {
	setHue(30);
	p = 0.10;
}

void ExpandingDisk::reset() {
	elapsedMillis = 0;
	x = Util::randomDouble(0, 1);
	y = Util::randomDouble(0, 1);
	xPixel = app.xPixels(x);
	yPixel = app.yPixels(y);
	radius = 0;
	dRadius = Util::randomDouble(0.00001, 0.0001);
	setHue(Util::randomInt(0, 360));
}

bool ExpandingDisk::draw(int i, int j) const {
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

void ExpandingDisk::update(int deltaMillis) {
	elapsedMillis += deltaMillis;
	radius += dRadius * deltaMillis;
	if (radius > 1) reset();
	radiusPixel = app.dPixels(radius);
}

void ExpandingDisk::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

