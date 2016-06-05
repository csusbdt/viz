#pragma once

class Drawable {
	public:
		Drawable(double p) : p(p) {}
		virtual ~Drawable() {}
		int getP() const { return p; }
		void setP(double p) { this->p = p; }
		virtual bool draw(int i, int j) const = 0;
	protected:
		double p;
};

