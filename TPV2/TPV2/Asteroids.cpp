#include "SDL_macros.h"
#include "Asteroids.h"
#include <assert.h>

using namespace std;

Asteroids::Asteroids() :
		game_(nullptr), //
		entityManager_(nullptr), //
		exit_(false) {
	initGame();
}

Asteroids::~Asteroids() {
	closeGame();
}

void Asteroids::initGame() {

	game_ = SDLGame::init("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_);

	entityManager_ = new EntityManager(game_);

	

	asteroid = entityManager_->addEntity();
	ast = asteroid->addComponent<AsteroidPool>();
	asteroid->addComponent<AsteroidsMotion>();
	asteroid->addComponent<AsteroidsViewer>();
	 

	bullet = entityManager_->addEntity();
	bull = bullet->addComponent<BulletsPool>();
	bullet->addComponent<BulletsMotion>();
	bullet->addComponent<BulletsViewer>();

	fighter = entityManager_->addEntity();
	fighterTR = fighter->addComponent<Transform>();
	vida = fighter->addComponent<Health>(3);
	fighter->addComponent<FighterCtrl>();
	fighter->addComponent<FighterMotion>();
	fighter->addComponent<FighterViewer>();
	fighter->addComponent<Gun>(bull);
	fighterTR->setPos(game_->getWindowWidth() / 2, game_->getWindowHeight() / 2);
	fighterTR->setWH(50, 50);

	gameManager = entityManager_->addEntity();
	gameManager->addComponent<ScoreManager>();
	gameManager->addComponent<GameLogic>(fighterTR, ast, bull,vida);
	gameManager->addComponent<ScoreViewer>();
	gameManager->addComponent<GameCtrl>(vida, ast);
}

void Asteroids::closeGame() {
	delete entityManager_;
	delete game_; game_ = nullptr;
	entityManager_ = nullptr;
	delete asteroid; asteroid = nullptr;
	delete bullet; bullet = nullptr;
	delete fighter; fighter = nullptr;
	delete gameManager; gameManager = nullptr;
	delete ast; ast = nullptr;
	delete bull; bull = nullptr;
	delete fighterTR; fighterTR = nullptr;
	delete vida; vida = nullptr;
	
}

void Asteroids::start() {
	exit_ = false;

	while (!exit_) {
		Uint32 startTime = game_->getTime();

		handleInput();
		update();
		render();

		Uint32 frameTime = game_->getTime() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

void Asteroids::stop() {
	exit_ = true;
}

void Asteroids::handleInput() {

	InputHandler *ih = InputHandler::instance();

	ih->update();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(SDLK_ESCAPE)) {
			exit_ = true;
		}

		if (ih->isKeyDown(SDLK_f)) {
			int flags = SDL_GetWindowFlags(game_->getWindow());
			if (flags & SDL_WINDOW_FULLSCREEN) {
				SDL_SetWindowFullscreen(game_->getWindow(), 0);
			} else {
				SDL_SetWindowFullscreen(game_->getWindow(),
						SDL_WINDOW_FULLSCREEN);
			}
		}
	}

}

void Asteroids::update() {
	entityManager_->update();
}

void Asteroids::render() {
	SDL_SetRenderDrawColor(game_->getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(game_->getRenderer());

	entityManager_->draw();

	SDL_RenderPresent(game_->getRenderer());
}

