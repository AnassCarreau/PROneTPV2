#pragma once

#include "Component.h"
#include "Transform.h"
#include "BulletsPool.h"
#include "Entity.h"

class Gun:public Component
{
private:
	Uint32 shoot = 250;
	Uint32 frame = 0;
	Transform* tr_;
	BulletsPool* bala;
public:
	bool disparo=true;
	Gun( BulletsPool* bullets):Component(ecs::Gun), bala(bullets), tr_(nullptr) {};
	virtual ~Gun() {};
	void update()override;
	void init() { tr_ = GETCMP2_(ecs::Transform, Transform);};
};

