#include "Game.hpp"

class GameObject {

private:

	float xpos, ypos;

	SDL_Texture* objTexture;
	SDL_FRect srcRect, destRect;

public:

	GameObject(const char* textureSheet, float x, float y);
	~GameObject();

	void update();
	void render();
};