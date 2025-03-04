#pragma once

#include "Components.hpp"
#include "SDL3/SDL.h"
#include "../TextureManager.hpp"
#include "Animation.hpp"
#include <map>

class SpriteComponent : public Component{

private:

	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_FRect srcRect, destRect;

	bool animated = false;
	int frames = 0;		// numar frame-uri
	int speed = 100;	// delay intre frame-uri in milisecunde

public:

	int animIndex = 0;	// care element din textura cu animatii sa afiseze
	std::map<const char*, Animation> animations;

	// ca sa nu mai faca moonwalk -> sa roteasca in jurul axei verticale sprite-ul
	// in functie de directia de deplasare
	SDL_FlipMode spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;

	SpriteComponent(const char* path) {

		transform = nullptr;
		texture = nullptr;
		setTex(path);
	}

	SpriteComponent(const char* path, bool isAnimated) {

		animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		play("Idle");

		setTex(path);
	}

	~SpriteComponent() {

		SDL_DestroyTexture(texture);
	}

	void setTex(const char* path) {

		texture = TextureManager::LoadTexture(path);
		if (texture == nullptr) {
			std::cout << "Atribuire invalida \"setTex(path)\" in \"SpriteComponent.hpp\"\n!";
			return;
		}
		
	}

	void init() override {

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;

		srcRect.w = 1.0f * transform->width;
		srcRect.h = 1.0f * transform->height;
	}

	void update() override {

		if (animated) {
			// TODO: trebuie revizuit procesul de casting de la int la float si invers
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = static_cast<float>(animIndex * transform->height);

		destRect.x = transform->position.x - Game::camera.x;
		destRect.y = transform->position.y - Game::camera.y;

		//	poate fi folosit static_cast<>

		destRect.w = transform->width * (1.0f * transform->scale);
		destRect.h = transform->height * (1.0f * transform->scale);
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void play(const char* animName) {
		// pentru a anima o textura

		if (animName == nullptr) {
			std::cout << "Atribuire invalida \"play()\" in \"SpriteComponent.hpp\"\n!";
			return;
		}

		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}
};