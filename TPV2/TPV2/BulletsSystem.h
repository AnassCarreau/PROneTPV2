#pragma once
#include "System.h"
#include "Entity.h"
#include "Transform.h"
#include "Manager.h"
#include "GameState.h"
#include "BulletsPool.h"

#include <cmath>
#include "Score.h"


class BulletsSystem : public System {
public:
	// - añadir una bala al juego, como en la práctica 1 pero usando entidades.
	// - no olvidar añadir la bala al grupo _grp_Bullet
	void shoot(Vector2D pos, Vector2D vel, double width, double height) {
		Entity* b = mngr_->addEntity<BulletsPool>(pos, vel, width, height);
		if (b != nullptr) {
			b->addToGroup<_grp_Bullet>();
		}
	};
		// - desactivar la bala “b”
	void onCollisionWithAsteroid(Entity* b, Entity* a) {
		b->setActive(false);
	};
		// - si el juego está parado no hacer nada.
		// - mover las balas y desactivar las que se salen de la ventana
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->jugando)
		{
			for (auto& o : mngr_->getGroupEntities<_grp_Bullet>())
			{
				if (o->isActive()) {
					Transform* tr_ = o->getComponent<Transform>();
					tr_->position_ = tr_->position_ + tr_->velocity_;
					if (tr_->position_.getX() >= game_->getWindowWidth()
						|| tr_->position_.getX() <= 0
						|| tr_->position_.getY() >= game_->getWindowHeight()
						|| tr_->position_.getY() <= 0)
					{

						o->setActive(false);
					}
				}
			}
		}
	};
};


