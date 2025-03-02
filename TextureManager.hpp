#pragma once

#include "Game.hpp"

class TextureManager {

private:

public:

	static SDL_Texture* LoadTexture(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_FRect src, SDL_FRect dest, SDL_FlipMode flip);

};