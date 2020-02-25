#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "BulletsPool.h"
#include "ver_7/Entity.h"

class BulletsMotion :public Component
{
private:
	BulletsPool* balas;
public:
	BulletsMotion(BulletsPool* balas_) : Component(ecs::BulletsMotion), balas(balas_) {};
	virtual ~BulletsMotion() {};
	void update()override
	{
		for (auto& o : balas->getPool())
		{
			if (o->isInUse()) {
				o->setPos(o->getPos() + o->getVel());
				if (o->getPos().getX() >= game_->getWindowWidth()
					|| o->getPos().getX() <= 0
					|| o->getPos().getY() >= game_->getWindowHeight()
					|| o->getPos().getY() <= 0)
				{

					o->isUse(false);
				}
			}
		}
	};
};

