#include "Game.hpp"

SDL_Texture* playerTex;
SDL_FRect srcR, destR;

Game::Game() {
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


	SDL_Surface* tempSurface = IMG_Load("assets/vadmirBasic.png");
	if (!tempSurface) {
		std::cout << "Crapa tempSurfaceu\n";
		return;
	}
	
	playerTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_DestroySurface(tempSurface);
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
	destR.h = 64;
	destR.w = 64;
	std::cout << cnt << std::endl;
}

void Game::render() {

	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Joc curatat\n";
}