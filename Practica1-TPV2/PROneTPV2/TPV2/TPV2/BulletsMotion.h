#pragma once

#include "Component.h"
#include "Transform.h"
#include "BulletsPool.h"
#include "Entity.h"
class BulletsMotion :public Component
{
private:
	BulletsPool* balas;
public:
	BulletsMotion() : Component(ecs::BulletsMotion), balas(nullptr) {};
	virtual ~BulletsMotion() {};
	void init()override
	{
		balas = GETCMP1_(BulletsPool);
	}
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

