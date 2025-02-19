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

	if (SDL_Init(SDL_INIT_VIDEO) == 1) {

		std::cout << "Subsystems initialized\n";

		window = SDL_CreateWindow(title, width, height, flags);
		if (window) {

			std::cout << "Window created\n";
		}
		else
			std::cout << "Crapa fereastra\n";

		renderer = SDL_CreateRenderer(window, NULL);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created\n";
		}
		else
			std::cout << "Crapa renderu\n";

		isRunning = true;
	}
	else{
		std::cout << "Crapa initu\n";
		isRunning = false;
	}
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
	std::cout << "Game cleaned\n";
}