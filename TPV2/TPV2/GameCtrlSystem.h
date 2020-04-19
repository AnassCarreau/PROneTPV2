#pragma once

#include "ecs.h"
#include "StarsSystem.h"
#include "System.h"
#include "Score.h"
#include "AsteroidPool.h"
#include "BulletsPool.h"
#include "Health.h"
#include "ScoreManager.h"


class GameCtrlSystem: public System {
private:
	AsteroidPool* ast_;
	BulletsPool* bullets_;
	Health* vida_;
	ScoreManager* scoreManager_;
public:
	void onFighterDeath() {
		// - a este método se le va a llamar cuando muere el caza.
		// - desactivar todos los asteroides y las balas.
		// - actualizar los componentes correspondientes (Score, GameState, …).
		ast_->disablAll();
		bullets_->disablAll();
	}
	void onAsteroidsExtenction() {
		// - crear una entidad, añade sus componentes (Score y GameState) y asociarla
		// con el handler _hndlr_GameState.
	}

	void init() override {
		Entity *e = mngr_->addEntity();
		auto sc = e->addComponent<Score>();
		sc->points_ = 0;
		mngr_->setHandler<_hdlr_GameState>(e);
	}

	void update() override {
		if (InputHandler::instance()->keyDownEvent() && scoreManager_->getPause()) {
			scoreManager_->setPause(false);
			scoreManager_->setPlay(true);
			//game_->getAudioMngr()->playMusic(Resources::Imperial, 5);

			//ast_->generateAsteroids(10);
		}
		if (!scoreManager_->getPlay()) {
			scoreManager_->setScore(0);
			vida_->ResetVidas();
		}
	}

};

