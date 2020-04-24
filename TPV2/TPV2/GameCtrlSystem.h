#pragma once

#include "ecs.h"
#include "System.h"
#include "Score.h"
#include "AsteroidsSystem.h"
#include "BulletsPool.h"
#include "Health.h"
#include "ScoreManager.h"
#include "GameState.h"
#include "Singleton.h"


class GameCtrlSystem: public System {
private:
	Entity* e;
public:
	void onFighterDeath() {
		// - a este método se le va a llamar cuando muere el caza.
		// - desactivar todos los asteroides y las balas.
		// - actualizar los componentes correspondientes (Score, GameState, …).
		AsteroidPool::instance()->disablAll();
		BulletsPool::instance()->disablAll();
		 mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_--;

		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		state->estado = state->pausado;
		
		
	}
	void onAsteroidsExtenction() {
		// - a este método se le va a llamar cuando no haya más asteroides.
// - desactivar todas las balas.
// - actualizar los componentes correspondientes (Score, GameState, …).
		//BulletsPool::instance()->disablAll();
		mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_=3;
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		state->win = true;
		 e->getComponent<Score>()->points_=0;
		
	}

	void init() override {
		e = mngr_->addEntity();
		auto sc = e->addComponent<Score>();
		sc->points_ = 0;
		mngr_->setHandler<_hdlr_GameState>(e);
	}
	// - si el juego está parado y el jugador pulsa ENTER empieza una nueva ronda:
// 1) añadir 10 asteroides llamando a addAsteroids del AsteroidsSystem.
// 2) actualizar el estado del juego y el número de vidas (si es necesario)
// en los componentes correspondientes (Score, Heath, GameState, …).
	void update() override {
		
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		
		
		if (InputHandler::instance()->keyDownEvent() && state->estado == state->pausado) {
			state->estado == state->jugando;
			//game_->getAudioMngr()->playMusic(Resources::Imperial, 5);
			mngr_->getSystem<AsteroidsSystem>()->addAsteroids(10);
		}
		if (state->estado == state->terminado) {
			
			mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_=3;
		}
	}

};

