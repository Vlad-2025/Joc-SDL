#pragma once

#include <string>
#include "SDL3/SDL.h"
#include "Components.hpp"

// implementare: AABB - Axis Aligned Bounding Box

class ColliderComponent :public Component{

private:

public:

	SDL_FRect collider;
	std::string tag;

	TransformComponent* transform;

	ColliderComponent(std::string _tag) {
		transform = nullptr;
		tag = _tag;
	}

	void init() override {

		if (!entity->hasComponent<TransformComponent>()) {

			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {

		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->width * (1.0f * transform->scale);
		collider.h = transform->height * (1.0f * transform->scale);
	}
};