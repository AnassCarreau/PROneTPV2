#pragma once

#include "Component.h"
#include "Transform.h"
#include "BulletsPool.h"
#include "Entity.h"

class Gun:public Component
{
private:
	Uint32 shoot = 2500;
	Uint32 frame = 0;
	Transform* tr_;
	BulletsPool* bala;
public:
	bool disparo=true;
	Gun( BulletsPool* bullets):Component(ecs::Gun), bala(bullets), tr_(nullptr) {};
	virtual ~Gun() { delete tr_; tr_ = nullptr; delete bala; bala = nullptr; };
	void update()override;
	void init() { tr_ = GETCMP2_(ecs::Transform, Transform);};
};

