#pragma once

#include "Drawable.h"
#include "Updatable.h"

class StartDisk : public Drawable, public Updatable {
	public:
		StartDisk();
		virtual bool draw(int i, int j) const;
		virtual void update(int deltaMillis);
		void reset();
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
};


