#pragma once

#include "Drawable.h"
#include "Updatable.h"

class ExpandingDisk : public Drawable, public Updatable {
	public:
		ExpandingDisk();
		virtual bool draw(int i, int j) const;
		virtual void update(int deltaMillis);
		void reset();
	//private:
		void setHue(int hue);
		double radius;
		double dRadius;
		double x;
		double y;
		double dy;
		unsigned char r;
		unsigned char g;
		unsigned char b;
		int xPixel;
		int yPixel;
		int radiusPixel;
		int elapsedMillis;
};


