#include "GameCtrl.h"

#include "Entity.h"
#include "InputHandler.h"

GameCtrl::GameCtrl(Health* vida, AsteroidPool* ast) :
	Component(ecs::GameCtrl),//
	scoreManager_(nullptr),
	vida_(vida),
	ast_(ast)//
{
}


void GameCtrl::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
	scoreManager_->setPlay(true);
}

void GameCtrl::update() {

	if (InputHandler::instance()->keyDownEvent() && scoreManager_->getPause()) {
		scoreManager_->setPause(false);
		scoreManager_->setPlay(true);
		game_->getAudioMngr()->playMusic(Resources::Imperial, 5);

		ast_->generateAsteroids(10);
	}
	if (!scoreManager_->getPlay() ) {
		scoreManager_->setScore(0);
		vida_->ResetVidas();
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

}
