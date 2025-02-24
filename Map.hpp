#pragma once

#include "Game.hpp"

class Map {

private:

	SDL_FRect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

public:

	Map();
	~Map();

	void loadMap(int arr[20][25]);
	void drawMap();
};