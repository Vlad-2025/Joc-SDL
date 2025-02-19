#ifndef Game_hpp

#define Game_hpp
#define SDL_MAIN_HANDLED

#include "SDL3/SDl.h"

#include <stdio.h>
#include <iostream>

class Game {

private:

	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

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
};

#endif // !Game_hpp
