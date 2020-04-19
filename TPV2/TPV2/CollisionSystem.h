#pragma once

#include "Collisions.h"
#include "System.h"
#include "Manager.h"
#include "AsteroidsSystem.h"
#include "FighterSystem.h"
#include "BulletsSystem.h"
#include "Transform.h"

class CollisionSystem: public System {
public:

	void update() {
		auto ptr = mngr_->getHandler<_hdlr_Fighter>()->getComponent<Transform>();
		for( auto& e : mngr_->getGroupEntities<_grp_Asteroid>()) {
			auto etr = e->getComponent<Transform>();
			if ( Collisions::collides(ptr->position_, ptr->width_, ptr->height_, etr->position_, etr->width_, etr->height_)) {
				mngr_->getSystem<FighterSystem>()->onCollisionWithAsteroid(e);
			}
			for (auto& b : mngr_->getGroupEntities<_grp_Bullet>()) {
				auto bull = b->getComponent<Transform>();
				if (Collisions::collides(etr->position_, etr->width_, etr->height_, bull->position_, bull->width_, bull->height_)) {
					mngr_->getSystem<AsteroidsSystem>()->onCollisionWithBullet(e, b);
					mngr_->getSystem<BulletsSystem>()->onCollisionWithAsteroid(b, e);
				}
			}
		}
	}
};

