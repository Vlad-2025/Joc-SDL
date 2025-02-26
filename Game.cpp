#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

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

		std::cout << "Subsystems initializat\n";

		window = SDL_CreateWindow(title, width, height, flags);
		if (!window) {

			std::cout << "Crapa Windowu\n";
			return;
		}
		std::cout << "Merge Windowu\n";

		renderer = SDL_CreateRenderer(window, NULL);
		if (!renderer) {
			
			std::cout << "Crapa rendereru\n";
			return;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout << "Merge rendereru\n";

		isRunning = true;
	}
	else
		std::cout << "Crapa initu\n";



	map = new Map();

	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("assets/vadmirBasic.png");
}

void Game::handleEvents() {

	SDL_Event event;
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

	cnt++;
	std::cout << cnt << "\t";
	//manager.refresh();
	manager.update();

	//if (player.getComponent<PositionComponent>().x() > 100) {
	//	//	std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//	player.getComponent<SpriteComponent>().setTex("assets/retep.png");
	//}
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