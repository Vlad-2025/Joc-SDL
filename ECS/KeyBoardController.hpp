#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {

private:



public:

	TransformComponent* transform;

	void init() override {

		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override {

	}

	if (Game::event) {


	}
};