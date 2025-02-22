#include "SDL3/SDL.h"
#include "Game.hpp"

Game* game = nullptr;

int main(int argc, const char * argv[]){

	using clock = std::chrono::steady_clock;

	using frames = std::chrono::duration<int, std::ratio<1, 60>>;

	game = new Game();

	game->init("Vadmir", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {

		/*
		
			deltaTime = CurrentTime() - OldTime;
			oldTime = CurrentTime();
			accumulator += deltaTime;

			while(accumulator > 1.0/60.0){
			
				update();
				accumulator -= 1.0/60.0;
			}

			render();
			display();

		*/

		auto start = clock::now();

		game->handleEvents();
		game->update();
		game->render();

		auto finish = clock::now();

		auto frameTime = finish - start;
		auto delay = frames(1) - frameTime;

		// pentru "0s"
		using namespace std::chrono_literals;
		using ms = std::chrono::milliseconds;

		if (delay > 0s) {
			auto delayMs = std::chrono::duration_cast<ms>(delay).count();
			SDL_Delay(static_cast<Uint32>(delayMs));
		}
		/*
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		*/
	}

	game->clean();

	return 0;
}