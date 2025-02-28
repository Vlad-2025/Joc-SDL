#pragma once
#include "SDL3/SDL.h"

class ColliderComponent;

class Collision {

private:

public:

	//	Axis-Aligned Bounding Box
	static bool AABB(const SDL_FRect& recA, const SDL_FRect& recB);
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};