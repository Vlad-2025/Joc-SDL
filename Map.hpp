#pragma once
#include <string>

class Map {

private:

public:

	Map();
	~Map();

	static void loadMap(std::string path, int sizeX, int sizeY);
	//void drawMap();
};