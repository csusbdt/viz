#include "ExpandingCircle.h"
#include "Util.h"
#include "App.h"
#include "global.h"
#include <cmath>

ExpandingCircle::ExpandingCircle() 
: Drawable(1), radius(0), x(0), y(0), r(255), g(255), b(255), dy(0), xPixel(0), yPixel(0), elapsedMillis(0), repetitions(3) {
	setHue(30);
	p = 0.30;
}

void ExpandingCircle::reset() {
	elapsedMillis = 0;
	x = Util::randomDouble(0, 1);
	y = Util::randomDouble(0, 1);
	xPixel = app.xPixels(x);
	yPixel = app.yPixels(y);
	radius = 0;
	radiusPixel = 0;
	dRadius = Util::randomDouble(0.00005, 0.0005);
	setHue(Util::randomInt(0, 360));
	repetitions = Util::randomInt(3, 9);
}

bool ExpandingCircle::draw(int i, int j) const {
	double distPixel = sqrt((xPixel - i) * (xPixel - i) + (yPixel - j) * (yPixel - j));
	// Convert distance from circle center to distance from circle edge.
	double dist = app.pixelToY(distPixel);
	if (dist < radius) {
		dist = radius - dist;
	} else {
		dist = dist - radius;
	}
	double prob = dist < 1 ? pow(1 - dist, 10) * p : 0;
	if (Util::randomBool(prob)) {
		app.draw(i, j, r, g, b);
		return true;
	} else {
		return false;
	}
}

void ExpandingCircle::update(int deltaMillis) {
	elapsedMillis += deltaMillis;
	radius += dRadius * deltaMillis;
	if (radius > 2) {
		if (--repetitions <= 0) {
			reset();
		} else {
			radius = 0;
		}
	} 
	radiusPixel = app.dPixels(radius);
}

void ExpandingCircle::setHue(int hue) {
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	r = Util::doubleToChar(fr);
	g = Util::doubleToChar(fg);
	b = Util::doubleToChar(fb);
}

