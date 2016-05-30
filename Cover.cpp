#include "Cover.h"
#include "Util.h"
#include "global.h"

bool Cover::draw(int i, int j) const {
	if (!Util::randomBool(prob)) return false;
	int hue = Util::randomInt(0, 360);
	double fr, fg, fb;
	Util::HSVtoRGB(&fr, &fg, &fb, hue, 1.0, 1.0);
	char r = Util::doubleToChar(fr);
	char g = Util::doubleToChar(fg);
	char b = Util::doubleToChar(fb);
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawPoint(renderer, i, j);
	return true;
}

