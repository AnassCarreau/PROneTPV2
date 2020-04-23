#pragma once
#include "System.h"
#include "Entity.h"
#include "ScoreManager.h"
#include "Transform.h"
#include "Manager.h"
#include "GameState.h"

class FighterGunSystem : public System {
public:
	// - si el juego est� parado no hacer nada.
	// - si el jugador pulsa SPACE, llamar a shoot(...) del BulletsSystem para a�adir
	// una bala al juego -- se puede disparar s�lo una bala cada 0.25sec.
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado != state->jugando)
		{
			InputHandler* ih = InputHandler::instance();
			if (ih->isKeyDown(SDLK_SPACE))
			{
				for (auto& b : mngr_->getGroupEntities<_grp_Bullet>()) {
					if (b->isActive() && disparo)
					{
						Transform* tr = b->getComponent<Transform>();
						Vector2D pos = tr->position_ + Vector2D(tr->width_ / 2, tr->height_ / 2) + Vector2D(0, -(tr->height_ / 2 + 5.0)).rotate(tr->rotation_);
						Vector2D vel = Vector2D(0, -1).rotate(tr->rotation_) * 2;
					//	mngr_->getSystem<BulletsSystem>()->shoot(pos, vel, 10, 10);
					
						frame = game_->getTime() + shootTime;
						disparo = false;
					}
				}
			}
			else if (frame <= game_->getTime())
			{
				if (!disparo)
				{
					disparo = true;
				}
			}
		}
		
	};
private:
	bool disparo = true;
	Uint32 shootTime = 2500;
	Uint32 frame = 0;
};


