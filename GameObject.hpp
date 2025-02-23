#include "Game.hpp"

class GameObject {

private:

	float xpos, ypos;

	SDL_Texture* objTexture;
	SDL_FRect srcRect, destRect;
	SDL_Renderer* renderer;


public:

	GameObject(const char* textureSheet, SDL_Renderer* ren, float x, float y);
	~GameObject();

	void update();
	void render();
};