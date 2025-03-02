#pragma once

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component {

public:

	Vector2D position;
	Vector2D velocity;
	int speed = 2;

	//	pentru coliziuni
	int height = 64;
	int width = 64;
	int scale = 1;


	TransformComponent() {

		position.Zero();
	}

	TransformComponent(int _scale) {

		position.x = 400;
		position.y = 320;
		scale = _scale;
	}

	TransformComponent(float x, float y) {

		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int _scale) {

		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = _scale;
	}

	void init() override {

		velocity.Zero();
	}

	void update() override {

		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};