#pragma once

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {

private:

public:

	TransformComponent* transform;
	SpriteComponent* sprite;

	KeyboardController() : transform(nullptr), sprite(nullptr) {}

	void init() override {

		transform = &entity->getComponent<TransformComponent>();
		if (transform == nullptr) {
			std::cout << "Atribuire invalida componenta \"TransformComponent\" la \"transform\" in \"init()\" din \"KeyBoardController\"!\n";
			return;
		}
		sprite = &entity->getComponent<SpriteComponent>();
		if (sprite == nullptr) {
			std::cout << "Atribuire invalida componenta \"SpriteComponent\" la \"sprite\" in \"init()\" din \"KeyBoardController\"!\n";
			return;
		}
	}

	void update() override {

		// TODO: trebuie schimbata tehnica de input la scancode
		// TODO: trebuie schimbata logica de miscare

		if (Game::event.type == SDL_EVENT_KEY_DOWN) {
			
			switch (Game::event.key.key) {

			case SDLK_W:
				transform->velocity.y = -1;
				sprite->play("Walk");
				break;

			case SDLK_A:
				transform->velocity.x = -1;
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
				sprite->play("Walk");
				break;

			case SDLK_S:
				transform->velocity.y = 1;
				sprite->play("Walk");
				break;

			case SDLK_D:
				transform->velocity.x = 1;
				sprite->play("Walk");
				break;

			default:
				break;
			}
		}

		if (Game::event.type == SDL_EVENT_KEY_UP) {
		
			switch (Game::event.key.key) {

			case SDLK_W:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;

			case SDLK_A:
				transform->velocity.x = 0;
				sprite->play("Idle");
				sprite->spriteFlip = SDL_FLIP_NONE;
				break;

			case SDLK_S:
				transform->velocity.y = 0;
				sprite->play("Idle");
				break;

			case SDLK_D:
				transform->velocity.x = 0;
				sprite->play("Idle");
				break;

			case SDLK_ESCAPE:
				Game::isRunning = false;
				break;

			default:
				break;
			}
		}
	}
};