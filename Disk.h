#pragma once

#include "Drawable.h"
#include "Updatable.h"

class Disk : public Drawable, public Updatable {
	public:
		Disk();
		//Disk(double p, double radius, double x, double y, char r, char g, char b);
		virtual bool draw(int i, int j) const;
		virtual void update(int deltaMillis);
		void setHue(int hue);

		double radius;
		double x;
		double y;
		unsigned char r;
		unsigned char g;
		unsigned char b;
	private:
		int xPixel;
		int yPixel;
		int radiusPixel;
};


