#include "Map.hpp"
#include "Game.hpp"
#include <fstream>

Map::Map() {

	
}

Map::~Map() {

	
}

void Map::loadMap(std::string path, int sizeX, int sizeY) {

	char c;
	std::fstream mapFile;
	if (path.empty()) {
		std::cout << "Crapa pasare \"path\" in \"Map.cpp\"!\n";
		return;
	}
	mapFile.open(path);

	int srcX, srcY;
	
	for (int row = 0; row < sizeY; row++) {
		for (int col = 0; col < sizeX; col++){

			mapFile.get(c);
			srcY = atoi(&c) * 32;
			mapFile.get(c);
			srcX = atoi(&c) * 32;
			Game::addTile(srcX, srcY, col * 32, row * 32);
			mapFile.ignore();
		}
		//mapFile.ignore();
	}

	mapFile.close();
}