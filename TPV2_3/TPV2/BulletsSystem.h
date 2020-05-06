#pragma once
#include "Entity.h"
#include "Manager.h"
#include "BulletsPool.h"
#include "Score.h"
#include "checkML.h"


class BulletsSystem : public System {
public:
	// - a�adir una bala al juego, como en la pr�ctica 1 pero usando entidades.
	// - no olvidar a�adir la bala al grupo _grp_Bullet
	void shoot(Vector2D pos, Vector2D vel, double width, double height) {
		Entity* b = mngr_->addEntity<BulletsPool>(pos, vel, width, height);
		if (b != nullptr) {
			b->addToGroup<_grp_Bullet>();
		}
	};
	// - desactivar la bala �b�
	void onCollisionWithAsteroid(Entity* b, Entity* a) {
		auto puntos = mngr_->getHandler<_hdlr_GameState>()->getComponent<Score>();
		puntos->points_ = puntos->points_ + 10;
		b->setActive(false);
	};
	// - si el juego est� parado no hacer nada.
	// - mover las balas y desactivar las que se salen de la ventana
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->Play)
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


