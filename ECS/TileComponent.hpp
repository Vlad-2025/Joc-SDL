#pragma once

#include "ECS.hpp"
#include "SDL3/SDL.h"

class TileComponent : public Component {

private:

public:

	SDL_Texture* texture;
	SDL_FRect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	~TileComponent() {
		SDL_DestroyTexture(texture);
	}

	TileComponent(float srcX, float srcY, float xpos, float ypos, const char* path) {

		texture = TextureManager::LoadTexture(path);
		if (texture == nullptr) {
			std::cout << "Atribuire invalida \"TextureManager::LoadTexture(path)\" la \"texture\" in \"TileComponent.hpp\"!\n";
		}

		//	daca modific scale-ul, trebuie si in "Map.cpp"

		/*	
			PROBLEMA: daca vreau sa fac destRect de 64x64, si schimb in "Map.cpp" ce este necesar,
			apare o margine de ~1pixel la fiecare tile, presupun ca e datorita diferentei intre SDL_FRect si SDL_Rect
			* CORECTIE: e de la imaginea descarcata de undeva, daca ii dau export din photoshop cu scale de 200%, arata corect
		*/

		// dreptunghi sursa
		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = 64;
		
		// dreptunghi destinatie
		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = 64;

		position.x = xpos;
		position.y = ypos;
	}

	void update() override {

		// pentru centrare camera asupra personajului
		destRect.x = position.x - Game::camera.x;
		destRect.y = position.y - Game::camera.y;
	}

	void draw() override {

		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};