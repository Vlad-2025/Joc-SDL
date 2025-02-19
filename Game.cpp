#include "Game.hpp"

Game::Game() {
}
Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen){

		flags = SDL_WINDOW_FULLSCREEN;
	}

	isRunning = false;

	if (SDL_Init(SDL_INIT_VIDEO) == 1) {

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


}

void Game::render() {

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Joc curatat\n";
}