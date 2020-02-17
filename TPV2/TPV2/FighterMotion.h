#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"

class FighterMotion:public Component
{
private:
	Transform *naveDelKibab;
public:
	FighterMotion() :Component(ecs::FighterMotion) { naveDelKibab = };
	virtual ~FighterMotion() {};
	void init();
};

