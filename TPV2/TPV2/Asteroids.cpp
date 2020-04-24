#include "SDL_macros.h"
#include "Asteroids.h"
#include <assert.h>

using namespace std;

Asteroids::Asteroids() :
		game_(nullptr), //
		mngr_(nullptr), //
		exit_(false) {
	initGame();
}

Asteroids::~Asteroids() {
	closeGame();
}

void Asteroids::initGame() {

	game_ = SDLGame::init("Asteroids", _WINDOW_WIDTH_, _WINDOW_HEIGHT_);

	AsteroidPool::init(10);
	BulletsPool::init(30);

	mngr_ = new Manager(game_);
	
	renderSystem_= mngr_->addSystem<RenderSystem>();
	 asteroidSystem_= mngr_->addSystem<AsteroidsSystem>();
	 bulletSystem_= mngr_->addSystem<BulletsSystem>();
	fighterSystem_= mngr_->addSystem<FighterSystem>();
	fighterGunSystem=mngr_->addSystem<FighterGunSystem>();
	collisionSystem_=mngr_->addSystem<CollisionSystem>();
	gameCtrlSystem_ = mngr_->addSystem<GameCtrlSystem>();

}

void Asteroids::closeGame() {
	delete mngr_;
	mngr_ = nullptr;
}

void Asteroids::start() {
	exit_ = false;
	auto ih = InputHandler::instance();
	while (!exit_) {
		SDL_SetRenderDrawColor(game_->getRenderer(), COLOR(0x00AAAAFF));
		SDL_RenderClear(game_->getRenderer());
		Uint32 startTime = game_->getTime();
		ih->update();
		if (ih->keyDownEvent() && ih->isKeyDown(SDLK_ESCAPE)) {
			exit_ = true;
			break;
		}
		mngr_->refresh();
		gameCtrlSystem_->update();
		asteroidSystem_->update();
		bulletSystem_->update();
		fighterSystem_->update();
	    fighterGunSystem->update();
		collisionSystem_->update();
		renderSystem_->update();

			Uint32 frameTime = game_->getTime() - startTime;
		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
		SDL_RenderPresent(game_->getRenderer());
	}
}

void Asteroids::stop() {
	exit_ = true;
}

/*void Asteroids::handleInput() {

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

}*/





