#pragma once

#include "ecs.h"
#include "StarsSystem.h"
#include "System.h"
#include "Score.h"
#include "AsteroidPool.h"
#include "AsteroidsSystem.h"
#include "BulletsPool.h"
#include "Health.h"
#include "ScoreManager.h"


class GameCtrlSystem: public System {
private:
	AsteroidPool* ast_;
	AsteroidsSystem* a;
	BulletsPool* bullets_;
	Health* vida_;
	ScoreManager* scoreManager_;
	Entity* e;
public:
	void onFighterDeath() {
		// - a este método se le va a llamar cuando muere el caza.
		// - desactivar todos los asteroides y las balas.
		// - actualizar los componentes correspondientes (Score, GameState, …).
		ast_->disablAll();
		bullets_->disablAll();
		vida_->RestaVida();
	}
	void onAsteroidsExtenction() {
		// - a este método se le va a llamar cuando no haya más asteroides.
// - desactivar todas las balas.
// - actualizar los componentes correspondientes (Score, GameState, …).
		bullets_->disablAll();
		vida_->ResetVidas();
		auto sc = e->addComponent<Score>();
		sc->points_ = 0;
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
		if (InputHandler::instance()->keyDownEvent() && scoreManager_->getPause()) {
			scoreManager_->setPause(false);
			scoreManager_->setPlay(true);
			//game_->getAudioMngr()->playMusic(Resources::Imperial, 5);
			a->addAsteroids(10);
		}
		if (!scoreManager_->getPlay()) {
			scoreManager_->setScore(0);
			vida_->ResetVidas();
		}
	}

};

