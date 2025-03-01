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

std::vector<ColliderComponent*> Game::colliders;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

	Map::loadMap("assets/p16x16.map", 32, 32);

	player.addComponent<TransformComponent>(1);
	player.addComponent<SpriteComponent>("assets/retep1.png");
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


	//	verificare coliziuni dintre player si obiecte de care se poate lovi dintr-un vector
	for(auto& i : colliders){
		Collision::AABB(player.getComponent<ColliderComponent>(), *i);
	}
}

void Game::render() {

	SDL_RenderClear(renderer);

	//map->drawMap();

	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Joc curatat\n";
}

void Game::addTile(int id, int x, int y) {

	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(x, y, 32, 32, id);


}