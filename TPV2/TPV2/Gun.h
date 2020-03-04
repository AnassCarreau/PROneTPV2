#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "BulletsPool.h"
#include "ver_7/Entity.h"

class Gun:public Component
{
private:
	Uint32 shoot = 25;
	Uint32 frame = 0;
	Transform* tr_;
	BulletsPool* bala;
public:
	bool disparo=true;
	Gun(Transform* fighter, BulletsPool* bullets):Component(ecs::Gun), tr_(fighter), bala(bullets) {};
	virtual ~Gun();
	void canshoot();
	void init() { tr_ = GETCMP2_(ecs::Transform, Transform);};
};

