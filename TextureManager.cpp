#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {

	SDL_Surface* tempSurface = IMG_Load(texture);
	if (!tempSurface) {
		std::cout << "Crapa creare \"tempSurface\" in \"TextureManager.cpp\"\n";
		return nullptr;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	if (!tex) {
		std::cout << "Crapa creare \"tex\" in \"TextureManager.cpp\"\n";
		return nullptr;
	}

	SDL_DestroySurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest, SDL_FlipMode flip) {

	SDL_RenderTextureRotated(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
}