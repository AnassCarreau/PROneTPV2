#pragma once
#include "System.h"
#include "Entity.h"

class FighterGunSystem : public System {
public:
	// - si el juego est� parado no hacer nada.
	// - si el jugador pulsa SPACE, llamar a shoot(...) del BulletsSystem para a�adir
	// una bala al juego -- se puede disparar s�lo una bala cada 0.25sec.
	void update() override {};
};

