#include "SDL_macros.h"
#include "Asteroids.h"
#include <assert.h>

#include "InputHandler.h"
#include "SDLGame.h"
#include "Entity.h"

//Componentes generales
#include "GameCtrl.h"
#include "GameLogic.h"
#include "Transform.h"

//Componentes caza
#include "FighterCtrl.h"
#include "FighterMotion.h"
#include "FighterViewer.h"
#include "Heart.h"
#include "Gun.h"

//Componentes balas
#include "BulletsPool.h"
#include "BulletsMotion.h"
#include "BulletsViewer.h"

//Componentes asteroides
#include "AsteroidPool.h"

//Componentes ScoreBoard
#include "ScoreManager.h"
#include "ScoreViewer.h"
#include "AsteroidsViewer.h"
#include "AsteroidsMotion.h"

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

	//Se crean las entidades y se le añaden los componentes
	Entity* bullets = entityManager_->addEntity();
	BulletsPool* poolCMPBullets = bullets->addComponent<BulletsPool>();
	bullets->addComponent<BulletsMotion>();
	bullets->addComponent<BulletsViewer>(game_->getTextureMngr()->getTexture(Resources::Bullet));

	Entity* asteroids = entityManager_->addEntity();
	AsteroidPool* poolCMPAsteroids = asteroids->addComponent<AsteroidPool>();
	asteroids->addComponent<AsteroidsMotion>();
	asteroids->addComponent<AsteroidsViewer>(game_->getTextureMngr()->getTexture(Resources::Asteroids));

	Entity* hunter = entityManager_->addEntity();
	Transform* hunterTR = hunter->addComponent<Transform>();
	hunterTR->setWH(45, 40);
	hunterTR->setPos(Vector2D(game_->getWindowWidth() / 2 - hunterTR->getW() / 2, game_->getWindowHeight() / 2 - hunterTR->getH() / 2));
	hunter->addComponent<FighterViewer>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
	Heart* hearts = hunter->addComponent<Heart>(game_->getTextureMngr()->getTexture(Resources::Heart));
	hunter->addComponent<FighterCtrl>(SDLK_UP, SDLK_LEFT, SDLK_RIGHT);
	hunter->addComponent<FighterMotion>();
	hunter->addComponent<Gun>(SDLK_SPACE, poolCMPBullets);

	Entity* gameManager = entityManager_->addEntity();
	gameManager->addComponent<ScoreManager>();
	gameManager->addComponent<GameLogic>(hunterTR, poolCMPAsteroids, poolCMPBullets, hearts);
	gameManager->addComponent<ScoreViewer>();
	gameManager->addComponent<GameCtrl>(poolCMPAsteroids, hearts);
}

void Asteroids::closeGame() {
	delete entityManager_;
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

