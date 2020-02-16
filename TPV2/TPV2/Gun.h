#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"
#include "BulletsPool.h"

class Gun:public Component
{
private:

public:
	Gun():Component(ecs::Gun) {};
	virtual ~Gun();
	void canshoot();
};

