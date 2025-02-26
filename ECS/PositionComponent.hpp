#pragma once

#include "Components.hpp"

class PositionComponent : public Component {

private:

	float xpos;
	float ypos;

public:

	PositionComponent() {

		xpos = 0;
		ypos = 0;
	}

	PositionComponent(float x, float y) {

		xpos = x;
		ypos = y;
	}

	float x() const { return xpos; }
	void x(float x) { xpos = x; }
	float y() const { return ypos; }
	void y(float y) { ypos = y; }

	void update() override {

		xpos++;
		ypos++;
	}

	void setPos(float x, float y) {
		xpos = x;
		ypos = y;
	}
};