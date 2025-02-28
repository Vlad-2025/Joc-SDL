#pragma once

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "SDL3/SDL.h"

class TileComponent : public Component {

private:

public:

	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id) {

		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0:
			path = "assets/apa100.png";
			break;
		case 1:
			path = "assets/pamant100.png";
			break;
		case 2:
			path = "assets/iarba100.png";
			break;

		default:
			break;
		}
	}

	void init() override {

		entity->addComponent<TransformComponent>(1.0*tileRect.x, 1.0 * tileRect.y, tileRect.w, tileRect.h, 1);

		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);

		sprite = &entity->getComponent<SpriteComponent>();
	}
};