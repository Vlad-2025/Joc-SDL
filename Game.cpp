#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "ECS/KeyBoardController.hpp"
#include "Collision.hpp"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Rect Game::camera = {0,0, 800, 640};

std::vector<ColliderComponent*> Game::colliders;
bool Game::isRunning = false;

auto& player(manager.addEntity());
//auto& wall(manager.addEntity());

const char* mapFile = "assets/terrain_ss1.png";

enum groupLabels : std::size_t {

	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
	//...32 grupuri posibile in total
};

//	listele prin care trecem pentru a randa obiectele
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));


Game::Game() {
	renderer = nullptr;
	window = nullptr;
	cnt = 0;
	isRunning = false;
}
Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen){

		flags = SDL_WINDOW_FULLSCREEN;
	}

	isRunning = false;

	if (SDL_Init(SDL_INIT_VIDEO)) {

		std::cout << "Subsisteme \"VIDEO\" initializate...\"\n";

		window = SDL_CreateWindow(title, width, height, flags);
		if (!window) {

			std::cout << "Initializare \"window\" esuata!\n";
			return;
		}
		std::cout << "Initializat \"Window\"...\n";

		renderer = SDL_CreateRenderer(window, NULL);
		if (!renderer) {
			
			std::cout << "Initializare \"renderer\" esuata!\n";
			return;
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout << "Initializat \"Renderer\"...\n";

		isRunning = true;
	}
	else
		std::cout << "Initializare subsisteme \"VIDEO\" esuata!\n";

	map = new Map();

	Map::loadMap("assets/map.map", 25, 20);

	player.addComponent<TransformComponent>(2);
	player.addComponent<SpriteComponent>("assets/player_anims1.png", false);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
}

void Game::handleEvents() {

	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_EVENT_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game::update() {

	///*cnt++;
	//std::cout << cnt << "\t";
	//if (!(cnt % 10))
	//	std::cout << std::endl;*/

	//manager.refresh();
	//manager.update();

	//Vector2D pVelocity = player.getComponent<TransformComponent>().velocity;
	//int pSpeed = player.getComponent<TransformComponent>().speed;

	//	verificare coliziuni dintre player si obiecte de care se poate lovi dintr-un vector
	//for(auto& i : colliders){
	//	Collision::AABB(player.getComponent<ColliderComponent>(), *i);
	//}

	//for (auto t : tiles) {

	//	t->getComponent<TileComponent>().destRect.x += -(pVelocity.x * pSpeed);
	//	t->getComponent<TileComponent>().destRect.y += -(pVelocity.y * pSpeed);
	//


	// prima data actualizam obiectele care trebuie incarcate si dupa le incarcam
	manager.refresh();
	manager.update();

	// pozitionare personaj in mijlocul ecranului <> centrare camera asupra personajului
	camera.x = player.getComponent<TransformComponent>().position.x - 400;
	camera.y = player.getComponent<TransformComponent>().position.y - 320;

	// pentru marginile hartii, ca sa nu le depaseasca camera
	if (camera.x < 0) camera.x = 0;
	if (camera.y < 0) camera.y = 0;

	if (camera.x > camera.w) camera.x = camera.w;
	if (camera.y > camera.h) camera.y = camera.h;
}


void Game::render() {

	SDL_RenderClear(renderer);

	//	manager.draw(); -> randa obiectele in ordinea formarii lor

	for (auto& t : tiles)	t->draw();
	for (auto& p : players) p->draw();
	for (auto& e : enemies) e->draw();

	SDL_RenderPresent(renderer);
}

void Game::addTile(int srcX, int srcY, float xpos, float ypos) {

	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapFile);
	tile.addGroup(groupMap);
}

void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Joc curatat\n";
}