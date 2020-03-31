#include "GameCtrl.h"
#include "Entity.h"
#include "InputHandler.h"

GameCtrl::GameCtrl(AsteroidPool* asteroidPool, Heart* heart) : 
	asteroidPool_(asteroidPool), heart_(heart), scoreManager_(nullptr), Component(ecs::GameCtrl){}

GameCtrl::~GameCtrl() {}

void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}

void GameCtrl::update() {
	if (InputHandler::instance()->keyDownEvent()) {
		if (!scoreManager_->isRunning()) {
			RandomNumberGenerator *r = game_->getRandGen();
			scoreManager_->setRunning(true);
			asteroidPool_->generateAsteroids(10);

			game_->getAudioMngr()->playMusic(Resources::Imperial, -1);

			//Resetea vidas y score
			if (scoreManager_->isFinish()) {
				scoreManager_->setFinishGame(false);
				heart_->resetHeart();
				scoreManager_->resetScore();
			}
		}
	}
}

void GameCtrl::draw() {
	if (!scoreManager_->isRunning()) {
		//PressAnyKey
		Texture *hitanykey = game_->getTextureMngr()->getTexture(Resources::PressAnyKey);
		hitanykey->render(game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2, game_->getWindowHeight() * 3 / 4);
	}
}
