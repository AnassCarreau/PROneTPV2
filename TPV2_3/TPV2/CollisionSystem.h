#pragma once
#include "Collisions.h"
#include "Manager.h"
#include "AsteroidsSystem.h"
#include "FighterSystem.h"
#include "BulletsSystem.h"
#include "Transform.h"
#include "GameCtrlSystem.h"
#include "checkML.h"

class CollisionSystem: public System {
public:
	// - si el juego está parado no hacer nada.
// - comprobar colisiones usando el esquema abajo (nota las instrucciones break
// y continue, piensa porque son necesarias).
	void update()override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->Play)
		{
			auto ptr = mngr_->getHandler<_hdlr_Fighter>()->getComponent<Transform>();
			for (auto& a : mngr_->getGroupEntities<_grp_Asteroid>()) {
				auto etr = a->getComponent<Transform>();
				if (Collisions::collides(ptr->position_, ptr->width_, ptr->height_, etr->position_, etr->width_, etr->height_)) {
					mngr_->getSystem<FighterSystem>()->onCollisionWithAsteroid(a);
					mngr_->getSystem<GameCtrlSystem>()->onFighterDeath();
					break;
				}
				for (auto& b : mngr_->getGroupEntities<_grp_Bullet>()) {
					if (!b->isActive())continue;
					if (!a->isActive())break;
					auto bull = b->getComponent<Transform>();
					if (Collisions::collides(etr->position_, etr->width_, etr->height_, bull->position_, bull->width_, bull->height_)) {
						mngr_->getSystem<AsteroidsSystem>()->onCollisionWithBullet(a, b);
						mngr_->getSystem<BulletsSystem>()->onCollisionWithAsteroid(b, a);
						
					}
				}
			}
		}
	}


};

