#pragma once

#include "Drawable.h"
#include "Updatable.h"

class BreathDisk : public Drawable, public Updatable {
	public:
		BreathDisk();
		virtual bool draw(int i, int j) const;
		virtual void update(int deltaMillis);
	//private:
		void setHue(int hue);
		double radius;
		double x;
		double y;
		double dy;
		char r;
		char g;
		char b;
		int xPixel;
		int yPixel;
		int radiusPixel;
		int elapsedMillis;
};


