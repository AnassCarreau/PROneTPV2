#pragma once

#include "System.h"

class CollisionSystem: public System {
public:
	//Esta clase no necesita recibir nada porque se encarga de  informar de las colisiones
	CollisionSystem();
	void update() override;
};

