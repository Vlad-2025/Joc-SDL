#pragma once

#include "Collision.hpp"
#include "ECS/ColliderComponent.hpp"

// implementare Axis-Aligned Bounding Box

bool Collision::AABB(const SDL_FRect& recA, const SDL_FRect& recB) {

	return
			recA.x + recA.w >= recB.x &&
			recB.x + recB.w >= recA.x &&
			recA.y + recA.h >= recB.y &&
			recB.y + recB.h >= recA.y;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB) {

	if (AABB(colA.collider, colB.collider)) {

		std::cout << colA.tag << " hit " << colB.tag << "\n";
		return true;
	}
	return false;
}

/*

	return SDL_HasIntersection(&recA, &recB);

*/