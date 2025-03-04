#include "SDL3/SDL.h"
#include "Game.hpp"

Game* game = nullptr;

int main(int argc, const char * argv[]){

	using clock = std::chrono::steady_clock;

	using frames = std::chrono::duration<int, std::ratio<1, 120>>;

	game = new Game();

	game->init("Vadmir", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	/*
	
		- trebuie gasita o solutie definitiva pentru frame-rate si inconsistentele la diferite frame-rateuri
		- solutia implementata este buna pentru consistenta intre frame-rateuri diferite, dar la valori mai mici 
			de 120fps apare screen-tearing
	
	*/

	const double dt = 1.0 / 60.0;
	double accumulator = 0.0;
	auto currentTime = clock::now();

	while (game->running()) {

		/*
			Algoritmul de baza
		
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

		auto newTime = clock::now();

		std::chrono::duration<double> frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime.count();

		while (accumulator >= dt) {
			// TODO: stabilit daca handleEvents() trebuie apelat in interiorul while-ului 
			//		 sau inainte
			game->handleEvents();
			game->update();
			accumulator -= dt;
		}

		game->render();

		auto finish = clock::now();
		auto frameDuration = finish - newTime;
		auto delay = frames(1) - frameDuration;

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