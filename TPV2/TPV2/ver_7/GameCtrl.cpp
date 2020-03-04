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
	scoreManager_->setPlay(true);

	//ast_ = GETCMP1_(AsteroidPool);
}

void GameCtrl::update() {

	if (InputHandler::instance()->keyDownEvent() && scoreManager_->getPause()) {
		scoreManager_->setPause(false);
		scoreManager_->setPlay(true);

		ast_->generateAsteroids(10);
	}
	if (!scoreManager_->getPlay() ) {
		scoreManager_->setScore(0);
		//vida_->ResetVidas();
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
