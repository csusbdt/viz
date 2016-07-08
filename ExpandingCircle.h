#pragma once

#include "Drawable.h"
#include "Updatable.h"

class ExpandingCircle : public Drawable, public Updatable {
	public:
		ExpandingCircle();
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
		char r;
		char g;
		char b;
		int xPixel;
		int yPixel;
		int radiusPixel;
		int elapsedMillis;
		int repetitions;
};


