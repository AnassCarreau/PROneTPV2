#include "GameCtrlSystem.h"

#include <cassert>
#include <cstdint>
#include "ecs.h"
#include "Entity.h"
#include "FighterInfo.h"
#include "FightersSystem.h"
#include "Manager.h"
#include "BulletsSystem.h"

using ecs::CmpId;

GameCtrlSystem::GameCtrlSystem() :
		System(ecs::_sys_GameCtrl) {
	state_ = WAITING;
	resetScore();
}

void GameCtrlSystem::init() {
	state_ = WAITING;
	mngr_->send<msg::Message>(msg::_PLAYER_INFO);

}

void GameCtrlSystem::update() {

	if (state_ != RUNNING && state_!=WAITING) {
		InputHandler *ih = game_->getInputHandler();
		if (ih->keyDownEvent() && ih->isKeyDown(SDLK_RETURN)) {
			mngr_->send<msg::Message>(msg::_START_REQ);
		}
	}
}

void GameCtrlSystem::startGame() {
	if (state_ == GAMEOVER) {
		resetScore();
	}
	mngr_->getSystem<FightersSystem>(ecs::_sys_Fighters)->resetFighterPositions();
	state_ = RUNNING;
}


void GameCtrlSystem::recieve(const msg::Message& msg)
{

	switch (msg.id) {
	case msg::_PLAYER_INFO: {

		auto gameState =
			mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getState();
		if (gameState==READY || msg.senderClientId == mngr_->getClientId())
			return;
		state_ = READY;
		mngr_->send<msg::Message>(msg::_PLAYER_INFO);
		break;
	}
	case msg::_CLIENT_DISCONNECTED: {
		auto gameState =
			mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getState();
		auto scoreIZQ=
			mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getScore(0);
		auto scoreDER=
			mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getScore(1);
		state_ = WAITING;

		scoreIZQ = scoreDER = 0;
		break;
	}
	case msg::_START_REQ: {
		auto gameState =
			mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getState();

		if (mngr_->getClientId() == 0 && gameState!=RUNNING) {
			mngr_->send<msg::Message>(msg::_START_ROUND);
		}
		break;
	}
	case msg::_START_ROUND:
		startGame();
		break;
	case msg::_ON_FIGHTER_DEATH:
		onFighterDeath(static_cast<const msg::OnFighterDeathMsg&>(msg).fighterId);
		mngr_->getSystem<BulletsSystem>(ecs::_sys_Bullets)->disableAll();
		break;
	case msg::_ON_FIGHTERS_DEATH:
		onFightersDeath();
		mngr_->getSystem<BulletsSystem>(ecs::_sys_Bullets)->disableAll();
		break;
	default:
		break;
	}
}

void GameCtrlSystem::onFighterDeath(uint8_t fighterId) {
	assert(fighterId >= 0 && fighterId <= 1);

	uint8_t id = 1 - fighterId; // the id of the other player fighter

	state_ = ROUNDOVER;
	score[id]++;
	if (score[id] == 3) 
		state_ = GAMEOVER;
	    

}

void GameCtrlSystem::onFightersDeath()
{
	state_ = ROUNDOVER;
}



void GameCtrlSystem::resetScore() {
	score[0] = score[1] = 0;
}
