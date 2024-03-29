#include "StartDisk.h"
#include "Util.h"
#include "App.h"
#include "global.h"
#include <cmath>

StartDisk::StartDisk() 
: Drawable(1), radius(.5), x(.5), y(2), r(255), g(255), b(255), dy(0), xPixel(0), yPixel(0) {
	setHue(180);
}

void StartDisk::reset() {
	y = 2;
}

bool StartDisk::draw(int i, int j) const {
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

void StartDisk::update(int deltaMillis) {
	if (y - radius > 1) {
		radius = Util::randomDouble(.03, .6);
		y = -radius;
		x = Util::randomDouble(radius/2, 1 - radius/2);
		setHue(Util::randomDouble(0, 360));
		dy = Util::randomDouble(.0001, .001);
		p = Util::randomDouble(.05, .28);
	}
	y += deltaMillis * dy;
	xPixel = app.xPixels(x);
	yPixel = app.yPixels(y);
	radiusPixel = app.dPixels(radius);
}

void StartDisk::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

