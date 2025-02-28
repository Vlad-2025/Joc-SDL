#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "ECS/KeyBoardController.hpp"
#include "Collision.hpp"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game() {
	renderer = nullptr;
	window = nullptr;
	cnt = 0;
	isRunning = false;
}
Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen){

		flags = SDL_WINDOW_FULLSCREEN;
	}

	isRunning = false;

	if (SDL_Init(SDL_INIT_VIDEO)) {

		std::cout << "Subsisteme VIDEO initializate\n";

		window = SDL_CreateWindow(title, width, height, flags);
		if (!window) {

			std::cout << "Crapa Windowul\n";
			return;
		}
		std::cout << "Merge Windowul\n";

		renderer = SDL_CreateRenderer(window, NULL);
		if (!renderer) {
			
			std::cout << "Crapa rendererul\n";
			return;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout << "Merge rendererul\n";

		isRunning = true;
	}
	else
		std::cout << "Crapa initul\n";

	map = new Map();

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/vadmirBasic1.png");
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/pamant100.png");
	wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents() {

	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game::update() {

	/*cnt++;
	std::cout << cnt << "\t";
	if (!(cnt % 10))
		std::cout << std::endl;*/

	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)) {
		//	functioneaza dar n-am ce face
	}
}

void Game::render() {

	SDL_RenderClear(renderer);

	map->drawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Joc curatat\n";
}