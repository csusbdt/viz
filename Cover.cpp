#include "Cover.h"
#include "Util.h"
#include "global.h"
#include <iostream> 

bool Cover::draw(int i, int j) const {
	if (Util::randomBool(p)) {
		int hue = Util::randomInt(0, 360);
		double fr, fg, fb;
		Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
		char r = Util::doubleToChar(fr);
		char g = Util::doubleToChar(fg);
		char b = Util::doubleToChar(fb);
		app.draw(i, j, r, g, b);
		return true;
	} else {
		return false;
	}
}

