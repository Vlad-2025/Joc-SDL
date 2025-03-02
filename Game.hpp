#pragma once 

#define Game_hpp
#define SDL_MAIN_HANDLED

#include "SDL3/SDL.h"
#include "SDL_image.h"

#include <chrono>
#include <stdio.h>
#include <iostream>
#include <vector>

class ColliderComponent;

class Game {

private:

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

	static void addTile(int srcX, int srcY, float xpos, float ypos);

	bool running() const {
		return isRunning;
	}

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static SDL_Rect camera;
	static std::vector<ColliderComponent*> colliders;
	static bool isRunning;
};