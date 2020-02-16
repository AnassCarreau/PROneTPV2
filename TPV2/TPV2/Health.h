#pragma once

#include "ver_7/Component.h"
#include "ver_7/Transform.h"

class Health: public Component
{
private:
	int vidas;
public:
	Health(int vidas_) :Component(ecs::Health) { vidas = vidas_; };
	virtual ~Health();
	void RestaVida();
	void ResetVidas() {
		vidas = 3;
	};
};

