#pragma once

#include "Drawable.h"
#include "Updatable.h"

class Disk : public Drawable, public Updatable {
	public:
		Disk() : prob(1), radius(.2), x(.5), y(.5), r(255), g(255), b(255) {}
		virtual bool draw(int i, int j) const;
		virtual void update(int deltaMillis);
		void setHue(int hue);

		double prob;
		double radius;
		double x;
		double y;
		char r;
		char g;
		char b;
};


