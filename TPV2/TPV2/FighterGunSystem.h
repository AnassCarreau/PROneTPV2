#pragma once
#include "System.h"
#include "Entity.h"

class FighterGunSystem : public System {
public:
	// - si el juego está parado no hacer nada.
	// - si el jugador pulsa SPACE, llamar a shoot(...) del BulletsSystem para añadir
	// una bala al juego -- se puede disparar sólo una bala cada 0.25sec.
	void update() override {};
};

