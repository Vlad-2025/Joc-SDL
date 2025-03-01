#pragma once

#include "Components.hpp"
#include "SDL3/SDL.h"
#include "../TextureManager.hpp"

class SpriteComponent : public Component{

private:

	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_FRect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;	// delay intre frameuri in milisecunde

public:

	SpriteComponent() = default;
	SpriteComponent(const char* path) {

		setTex(path);
	}

	SpriteComponent(const char* path, int numberFrames, int animationSpeed) {

		animated = true;
		frames = numberFrames;
		speed = animationSpeed;

		setTex(path);
	}

	~SpriteComponent() {

		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path) {

		texture = TextureManager::LoadTexture(path);
	}

	void init() override {

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		//srcRect.w = srcRect.h = 832;	 TERBUIE NEAPARAT REPARAT
		//destRect.w = destRect.h = 64;

		srcRect.w = 1.0f * transform->width;
		srcRect.h = 1.0f * transform->height;
	}

	void update() override {

		if (animated) {

			srcRect.x = srcRect.w * (static_cast<int>(SDL_GetTicks() / speed) % frames);
		}

		destRect.x = transform->position.x;
		destRect.y = transform->position.y;

		//	poate fi folosit static_cast<>

		destRect.w = transform->width * (1.0f * transform->scale);
		destRect.h = transform->height * (1.0f * transform->scale);
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect);
	}
};