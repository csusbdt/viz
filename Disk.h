#pragma once

#include "Drawable.h"

class Disk : public Drawable {
	public:
		Disk() : prob(1), radius(.2), x(.5), y(.5), r(255), g(255), b(255) {}
		virtual bool draw(int i, int j) const;
		void setHue(int hue);

		double prob;
		double radius;
		double x;
		double y;
		char r;
		char g;
		char b;
};


