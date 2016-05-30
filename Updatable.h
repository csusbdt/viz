#pragma once

class Updatable {
	public:
		virtual ~Updatable() {}
		virtual void update(int deltaMillis) = 0;
};

