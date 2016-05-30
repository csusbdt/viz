#pragma once

class Drawable {
	public:
		virtual ~Drawable() {}
		virtual bool draw(int i, int j) const = 0;
};

