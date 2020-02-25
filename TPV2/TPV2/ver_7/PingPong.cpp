#include "SDL_macros.h"
#include "PingPong.h"
#include <assert.h>
#include "BallMoveBehaviour.h"
#include "GameCtrl.h"
#include "GameLogic.h"
#include "InputHandler.h"
#include "PaddleKBCtrl.h"
#include "PaddleMouseCtrl.h"
#include "PaddleMoveBehaviour.h"
#include "Rectangle.h"
#include "ScoreManager.h"
#include "ScoreViewer.h"
#include "SimpleMoveBahviour.h"
#include "Transform.h"
#include "SDLGame.h"
#include "..//FighterCtrl.h"
#include "..//FighterViewer.h"
#include "..//FighterMotion.h"
#include "..//Health.h"
#include "ObjectPool.h"
#include "..//AsteroidPool.h"
#include "..//Asteroid.h"
#include "..//AsteroidsViewer.h"
#include "..//AsteroidsMotion.h"
#include "..//BulletsMotion.h"
#include "..//BulletsPool.h"
#include "..//BulletsViewer.h"
#include "..//Bullet.h"
#include "SDL_macros.h"

using namespace std;

PingPong::PingPong() :
		game_(nullptr), //
		entityManager_(nullptr), //
		exit_(false) {
	initGame();
}

PingPong::~PingPong() {
	closeGame();
}

void PingPong::initGame() {

	game_ = SDLGame::init("Ping Pong", _WINDOW_WIDTH_, _WINDOW_HEIGHT_);

	entityManager_ = new EntityManager(game_);

	Entity* fighter = entityManager_->addEntity();
	Transform* fighterTR = fighter->addComponent<Transform>();
	fighter->addComponent<FighterCtrl>();
	fighter->addComponent<FighterMotion>();
	fighter->addComponent<FighterViewer>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
	fighter->addComponent<Health>(3);
	fighterTR->setPos(game_->getWindowWidth()/2, game_->getWindowHeight() / 2);
	fighterTR->setWH(50, 50);


	Entity* asteroid = entityManager_->addEntity();
	AsteroidPool* ast = asteroid->addComponent<AsteroidPool>();
	asteroid->addComponent<AsteroidsMotion>(ast);
	asteroid->addComponent<AsteroidsViewer>(ast);
	 

	Entity* bullet = entityManager_->addEntity();
	BulletsPool* bull = bullet->addComponent<BulletsPool>();
	bullet->addComponent<BulletsMotion>(bull);
	bullet->addComponent<BulletsViewer>(bull);

	Entity *gameManager = entityManager_->addEntity();
	gameManager->addComponent<ScoreManager>();
	gameManager->addComponent<GameLogic>(fighterTR, ast, bull);
	gameManager->addComponent<ScoreViewer>();
	gameManager->addComponent<GameCtrl>(fighterTR);
}

void PingPong::closeGame() {
	delete entityManager_;
}

void PingPong::start() {
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

void PingPong::stop() {
	exit_ = true;
}

void PingPong::handleInput() {

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

void PingPong::update() {
	entityManager_->update();
}

void PingPong::render() {
	SDL_SetRenderDrawColor(game_->getRenderer(), COLOR(0x00AAAAFF));
	SDL_RenderClear(game_->getRenderer());

	entityManager_->draw();

	SDL_RenderPresent(game_->getRenderer());
}

