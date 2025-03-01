#include "Map.hpp"
#include "Game.hpp"
#include <fstream>

Map::Map() {

	
}

Map::~Map() {

	
}

void Map::loadMap(std::string path, int sizeX, int sizeY) {

	char tile;
	std::fstream mapFile;
	if (path.empty()) {
		std::cout << "Crapa pasare \"path\" in \"Map.cpp\"!\n";
		return;
	}
	mapFile.open(path);
	
	for (int row = 0; row < sizeY; row++) {
		for (int col = 0; col < sizeX; col++){
			mapFile.get(tile);
			//Game::addTile(atoi(&tile), col * 32, row * 32);
			std::cout << tile << " ";
			//mapFile.ignore();
		}
		//mapFile.ignore();
	}

	mapFile.close();
}