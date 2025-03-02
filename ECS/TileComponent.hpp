#pragma once

#include "ECS.hpp"
#include "SDL3/SDL.h"

class TileComponent : public Component {

private:

public:

	SDL_Texture* texture;
	SDL_FRect srcRect, destRect;

	TileComponent() = default;

	~TileComponent() {
		SDL_DestroyTexture(texture);
	}

	TileComponent(float srcX, float srcY, float xpos, float ypos, const char* path) {

		texture = TextureManager::LoadTexture(path);
		if (texture == nullptr) {
			std::cout << "\nCrapa atribuire \"TextureManager::LoadTexture(path)\" la \"texture\" in \"TileComponent.hpp\"!\n";
		}

		//	daca modific scale-ul, trebuie si in "Map.cpp"

		/*	
			PROBLEMA: daca vreau sa fac destRect de 64x64, si schimb in "Map.cpp" ce este necesar,
			apare o margine de ~1pixel la fiecare tile, presupun ca e datorita diferentei intre SDL_FRect si SDL_Rect
		*/		
		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 32;
		
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = 32;
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};