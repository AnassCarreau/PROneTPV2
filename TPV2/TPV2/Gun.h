#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "BulletsPool.h"

class Gun:public Component
{
private:
	Uint32 shoot = 2500;
	Uint32 frame = 0;
public:
	bool disparo=true;
	Gun():Component(ecs::Gun) {};
	virtual ~Gun();
	void canshoot();
};

