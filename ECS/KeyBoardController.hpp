#pragma once

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {

private:

public:

	TransformComponent* transform;

	void init() override {

		transform = &entity->getComponent<TransformComponent>();

		if (transform == nullptr) {
			std::cout << "Crapa atribuire componenta \"TransformComponent\" la \"transform\" in \"init()\" din \"KeyBoardController\"!\n";
			return;
		}
	}

	void update() override {

		// trebuie schimbata tehnica de input la scancode

		if (Game::event.type == SDL_EVENT_KEY_DOWN) {
			
			switch (Game::event.key.key) {

			case SDLK_W:
				transform->velocity.y = -1;
				break;

			case SDLK_A:
				transform->velocity.x = -1;
				break;

			case SDLK_S:
				transform->velocity.y = 1;
				break;

			case SDLK_D:
				transform->velocity.x = 1;
				break;

			default:
				break;
			}
		}

		if (Game::event.type == SDL_EVENT_KEY_UP) {
		
			switch (Game::event.key.key) {

			case SDLK_W:
				transform->velocity.y = 0;
				break;

			case SDLK_A:
				transform->velocity.x = 0;
				break;

			case SDLK_S:
				transform->velocity.y = 0;
				break;

			case SDLK_D:
				transform->velocity.x = 0;
				break;

			default:
				break;
			}
		}
	}
};