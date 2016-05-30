#pragma once

#include "Drawable.h"

class Cover : public Drawable {
	public:
		Cover() : prob(1) {}
		virtual bool draw(int i, int j) const;
		double prob;
};

