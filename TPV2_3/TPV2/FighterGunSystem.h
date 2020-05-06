#pragma once
#include "checkML.h"

class FighterGunSystem : public System {
public:
	FighterGunSystem():disparo(true),shootTime(2500),frame(0){}
	// - si el juego est� parado no hacer nada.
	// - si el jugador pulsa SPACE, llamar a shoot(...) del BulletsSystem para a�adir
	// una bala al juego -- se puede disparar s�lo una bala cada 0.25sec.
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->Play)
		{
			InputHandler* ih = InputHandler::instance();
			if (ih->isKeyDown(SDLK_SPACE) && disparo)
			{
				game_->getAudioMngr()->playChannel(Resources::GunShot, 0,1);

				Transform* tr = mngr_->getHandler<_hdlr_Fighter>()->getComponent<Transform>();
				Vector2D pos = tr->position_ + Vector2D(tr->width_ / 2, tr->height_ / 2) + Vector2D(0, -(tr->height_ / 2 + 5.0)).rotate(tr->rotation_);
				Vector2D vel = Vector2D(0, -1).rotate(tr->rotation_) * 2;
				mngr_->getSystem<BulletsSystem>()->shoot(pos, vel, 10, 10);
				frame = game_->getTime() + shootTime;
				disparo = false;
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
	bool disparo ;
	Uint32 shootTime ;
	Uint32 frame ;
};

