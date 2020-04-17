#pragma once

#include "ecs.h"
#include "StarsSystem.h"
#include "System.h"
#include "Score.h"
#include "AsteroidPool.h"
#include "BulletsPool.h"
#include "Health.h"


class GameCtrlSystem: public System {
private:
	AsteroidPool* ast_;
	BulletsPool* bullets_;
	Health* vida_;
public:
	void onFighterDeath() {
		// - a este m�todo se le va a llamar cuando muere el caza.
		// - desactivar todos los asteroides y las balas.
		// - actualizar los componentes correspondientes (Score, GameState, �).
		ast_->disablAll();
		bullets_->disablAll();
	}
	void onAsteroidsExtenction() {
		// - crear una entidad, a�ade sus componentes (Score y GameState) y asociarla
		// con el handler _hndlr_GameState.
	}

	void init() override {
		Entity *e = mngr_->addEntity();
		auto sc = e->addComponent<Score>();
		sc->points_ = 0;
		mngr_->setHandler<_hdlr_GameState>(e);
	}

	void update() override {
		auto ih = game_->getInputHandler();

		if ( ih->keyDownEvent() && ih->isKeyDown(SDLK_RETURN)) {
			mngr_->getSystem<StarsSystem>()->addStars(10);
		}
	}

};

