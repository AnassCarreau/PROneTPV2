#include "GameCtrlSystem.h"

#include "FoodSystem.h"
#include "SDLGame.h"
#include "Manager.h"
#include "GameState.h"
#include "GhostsSystem.h"
#include "PacManSystem.h"

GameCtrlSystem::GameCtrlSystem() :
		System(ecs::_sys_GameCtrl), //
		gameState_(nullptr) {
}


void GameCtrlSystem::init() {
	Entity *e = mngr_->addEntity();
	gameState_ = e->addComponent<GameState>();
	mngr_->setHandler(ecs::_hdlr_GameStateEntity, e);
}

void GameCtrlSystem::update() {

	if ( gameState_->state_ == GameState::RUNNING )
		return;

	auto ih = game_->getInputHandler();

	if ( ih->keyDownEvent() && ih->isKeyDown(SDLK_RETURN)) {
		switch ( gameState_->state_) {
		case GameState::READY:
			gameState_->state_ = GameState::RUNNING;
			//Ya no hace falta añadir nada  porque cada clase activa  sus elementos al recibir el mensaje de start
	       //y el pacman se resetea con ese mensaje
			mngr_->send<msg::Message>(msg::_GAME_START);
			break;
		case GameState::OVER:
			gameState_->state_ = GameState::READY;
			gameState_->score_ = 0;
			gameState_->won_ = false;
			//Se manda el mensaje de partida finalizada
			mngr_->send<msg::Message>(msg::_GAME_OVER);
			break;
		default:
			assert(false); // should not be rechable
			break;
		}
	}
}

void GameCtrlSystem::recieve(const msg::Message& msg)
{
	//Si se come la ultima cereza se gana la partida y si es una colision se pierde la partida
	switch (msg.id) {
	case msg::_COLLISION: 
		onPacManDeath();
		break;
	case msg::_NO_CHERRY: 
		onNoMoreFood();
		break;
	default:
		break;
	}
}

void GameCtrlSystem::onPacManDeath() {
	gameState_->state_ = GameState::OVER;
	gameState_->won_ = false;
	//mngr_->getSystem<GhostsSystem>(ecs::_sys_Ghosts)->disableAll();
	//mngr_->getSystem<FoodSystem>(ecs::_sys_Food)->disableAll();
	//Ya no hace falta desactivar nada porque cada clase desactiva sus elementos al recibir el mensaje de colision
}

void GameCtrlSystem::onNoMoreFood() {
	//Antes//mngr_->getSystem<GhostsSystem>(ecs::_sys_Ghosts)->disableAll();
	//Antes//mngr_->getSystem<FoodSystem>(ecs::_sys_Food)->disableAll();	
	//Ya no hace falta desactivar nada porque cada clase desactiva sus elementos al recibir el mensaje de no cherry
	gameState_->state_ = GameState::OVER;
	gameState_->won_ = true;
}

/*void GameCtrlSystem::startGame() {
	mngr_->send<msg::Message>(msg::_GAME_START);
	mngr_->getSystem<FoodSystem>(ecs::_sys_Food)->addFood(10);
	mngr_->getSystem<GhostsSystem>(ecs::_sys_Ghosts)->addGhosts(2);
	mngr_->getSystem<PacManSystem>(ecs::_sys_PacMan)->resetPacManPosition();
	
}*/
