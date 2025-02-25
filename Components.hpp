#include "ECS.hpp"

class PositionComponent : public Component {

private:

	int xpos;
	int ypos;

public:

	PositionComponent() {
		xpos = 0;
		ypos = 0;
	}

	int x() const { return xpos; }
	int y() const { return ypos; }

	void init() override {

		xpos = 0;
		ypos = 0;
	}

	void update() override {

		xpos++;
		ypos++;
	}

	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
};