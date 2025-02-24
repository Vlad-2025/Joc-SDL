#ifndef Game_hpp

#define Game_hpp
#define SDL_MAIN_HANDLED

#include "SDL3/SDL.h"
#include "SDL_image.h"

#include <chrono>
#include <stdio.h>
#include <iostream>

class Game {

private:

	bool isRunning;
	SDL_Window* window;
	int cnt;

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() const {
		return isRunning;
	}

	static SDL_Renderer* renderer;
};

#endif // !Game_hpp
