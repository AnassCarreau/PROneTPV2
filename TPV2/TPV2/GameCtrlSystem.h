#pragma once
#include "Score.h"
#include "BulletsPool.h"
#include "Health.h"
#include "checkML.h"

class GameCtrlSystem : public System {
public:
	void init() override {
		Entity* e = mngr_->addEntity();
		e->addComponent<Score>()->points_ = 0;
		mngr_->setHandler<_hdlr_GameState>(e);
		auto state = e->addComponent<GameState>();
		state->estado = state->Start;
		mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_ = 3;
	}
     // - a este método se le va a llamar cuando muere el caza.
	// - desactivar todos los asteroides y las balas.
   // - actualizar los componentes correspondientes (Score, GameState, …).
	void onFighterDeath() {
		AsteroidPool::instance()->disableAll();
		BulletsPool::instance()->disableAll();
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		auto vida = mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>();
		vida->vidas_--;
		if (vida->vidas_ == 0)
		{
			state->estado = state->FinishLose;
		}
		else state->estado = state->Pause;

	}
	//- a este método se le va a llamar cuando no haya más asteroides.
   //- desactivar todas las balas.
  //- actualizar los componentes correspondientes (Score, GameState, …).
	void onAsteroidsExtenction() {
		BulletsPool::instance()->disableAll();
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		state->estado = state->FinishWin;
	}


   // - si el juego está parado y el jugador pulsa ENTER empieza una nueva ronda:
  // 1) añadir 10 asteroides llamando a addAsteroids del AsteroidsSystem.
 // 2) actualizar el estado del juego y el número de vidas (si es necesario)
// en los componentes correspondientes (Score, Heath, GameState, …).
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (InputHandler::instance()->keyDownEvent() && state->estado != state->Play) {
			game_->getAudioMngr()->playMusic(Resources::Imperial, 0);
			mngr_->getHandler<_hdlr_GameState>()->getComponent<Score>()->points_ = 0;
			mngr_->getSystem<AsteroidsSystem>()->addAsteroids(10);
			if (state->estado == state->FinishWin || state->estado == state->FinishLose)
			{
				mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_ = 3;
			}
			state->estado = state->Play;


		}

	}

};

