#include "GameCtrl.h"

#include "Entity.h"
#include "InputHandler.h"

GameCtrl::GameCtrl(Transform *ballTR) :
		Component(ecs::GameCtrl), //
		ballTR_(ballTR), //
		scoreManager_(nullptr) ,
	vida_(nullptr),
	ast_(nullptr)//
{
}

GameCtrl::~GameCtrl() {
}

void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
	vida_ = GETCMP1_(Health);
	ast_ = GETCMP1_(AsteroidPool);
}

void GameCtrl::update() {

	if (InputHandler::instance()->keyDownEvent()) {
		if (scoreManager_->getPausing()) {
			scoreManager_->setPausing(false);
			ast_->generateAsteroids(10);
			// rest the score if the game is over
			if (scoreManager_->getRunning()) {
				vida_->ResetVidas();
				scoreManager_->setScore(0);
			}
		}
	}
}

void GameCtrl::draw() {

	if (scoreManager_->getPausing()) {
		Texture *hitanykey = game_->getTextureMngr()->getTexture(
				Resources::PressAnyKey);
		hitanykey->render(
				game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2,
				game_->getWindowHeight() - hitanykey->getHeight() - 50);
	}

	// game over message when game is over
	if (!scoreManager_->getRunning() ) {
		Texture *gameOver = game_->getTextureMngr()->getTexture(
				Resources::GameOver);
		gameOver->render(game_->getWindowWidth() / 2 - gameOver->getWidth() / 2,
				game_->getWindowHeight() - gameOver->getHeight() - 150);
	}
}
