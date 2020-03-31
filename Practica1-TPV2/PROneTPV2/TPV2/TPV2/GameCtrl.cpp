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
}

void GameCtrl::update() {

	if (InputHandler::instance()->keyDownEvent() && scoreManager_->isPause()) {
		scoreManager_->setPause(false);
		game_->getAudioMngr()->playMusic(Resources::Imperial, 5);

		ast_->generateAsteroids(10);
		if (!scoreManager_->isPlay()) {
			scoreManager_->setPlay(true);

			scoreManager_->setScore(0);
			vida_->ResetVidas();
		}
	}
	
}

void GameCtrl::draw() {

	if (scoreManager_->isPause()) {
		Texture* hitanykey = game_->getTextureMngr()->getTexture(
			Resources::PressAnyKey);
		hitanykey->render(
			game_->getWindowWidth() / 2 - hitanykey->getWidth() / 2,
			game_->getWindowHeight() - hitanykey->getHeight() - 50);
	}

}
