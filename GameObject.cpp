#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, float x, float y) {

	xpos = x;
	ypos = y;

	if (textureSheet != 0){
		objTexture = TextureManager::LoadTexture(textureSheet);
		if (!objTexture) {
			std::cout << "Crapa atribuire \"LoadTexture(...)\" la \"objTexture\" in \"GameObject.cpp\"\n";
			objTexture = nullptr;
		}
	}
	else{
		std::cout << "Crapa atribuire \"LoadTexture(...)\" la \"objTexture\" in \"GameObject.cpp\" de la \"textureSheet\" sau \"ren\"\n";
		objTexture = nullptr;
	}
}

GameObject::~GameObject() {
		
}

void GameObject::update() {

	// problema blurare la upscale de la 32x32 pixeli la 64x64 pixeli
	// daca fac srcRect de 832x832 pixeli si downscale la 64x64 pixeli se vede corect,
	// dar ocupa mai mult spatiu si nu am gasit alta optiune pentru upscale

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	// pentru texturi de 32x32 cu upscale la 64x64, dar nu se vad bine (momentan)
	destRect.h = 32 * 2;
	destRect.w = 32 * 2;

	destRect.x = xpos;
	destRect.y = ypos;

	xpos++;
	ypos++;
	
}

void GameObject::render() {

	//	problema la &srcRect (unde e NULL)
	
	SDL_RenderTexture(Game::renderer, objTexture, &srcRect, &destRect);
}