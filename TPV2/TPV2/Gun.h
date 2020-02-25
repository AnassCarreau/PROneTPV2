#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "BulletsPool.h"
#include "ver_7/Entity.h"

class Gun:public Component
{
private:
	Uint32 shoot = 2500;
	Uint32 frame = 0;
	Transform* tr_;
	BulletsPool* bala;
public:
	bool disparo=true;
	Gun():Component(ecs::Gun), tr_(nullptr) {};
	virtual ~Gun();
	void canshoot();
	void init() { tr_ = GETCMP2_(ecs::Transform, Transform); };
};

