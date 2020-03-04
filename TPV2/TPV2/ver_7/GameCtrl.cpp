#include "GameCtrl.h"

#include "Entity.h"
#include "InputHandler.h"

GameCtrl::GameCtrl(Transform* fighterTR, AsteroidPool* ast) :
	Component(ecs::GameCtrl), fighterTR_(fighterTR),//
	scoreManager_(nullptr),
	vida_(nullptr),
	ast_(ast)//
{
}

GameCtrl::~GameCtrl() {
}

void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
	
	//ast_ = GETCMP1_(AsteroidPool);
}

void GameCtrl::update() {

	if (InputHandler::instance()->keyDownEvent() && scoreManager_->getPause()) {
		scoreManager_->setPause(false);
		scoreManager_->setPlay(true);
		ast_->generateAsteroids(10);
	}
	if (!scoreManager_->getPlay() && scoreManager_->getGameOver()) {
		//vida_->ResetVidas();
		scoreManager_->setScore(0);
	}
}

void GameCtrl::draw() {

	if (scoreManager_->getPause()) {
		Texture* hitanykey = game_->getTextureMngr()->getTexture(
			Resources::PressAnyKey);
		hitanykey->render(
			game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2,
			game_->getWindowHeight() - hitanykey->getHeight() - 50);
	}

	// game over message when game is over
	if (!scoreManager_->getPlay() && scoreManager_->getGameOver()) {
		Texture* gameOver = game_->getTextureMngr()->getTexture(
			Resources::GameOver);
		gameOver->render(game_->getWindowWidth() / 2 - gameOver->getWidth() / 2,
			game_->getWindowHeight() - gameOver->getHeight() - 150);
	}
}
