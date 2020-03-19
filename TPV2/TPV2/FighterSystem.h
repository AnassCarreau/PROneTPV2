#pragma once
#include "System.h"
#include "Entity.h"

class FighterSystem : public System {
public:
	// - poner el caza en el centro con velocidad 0 y rotaci�n 0. No hace falta
	// desactivar la entidad (no dibujarla si el juego est� parado en RenderSystem).
	void onCollisionWithAsteroid(Entity* a) {};
	// - crear la entidad del caza, a�adir sus componentes (Transform, Health, etc.)
	// y asociarla con el handler _hndlr_Fighter.
	void init() override {};
		// - si el juego est� parado no hacer nada.
		// - actualizar la velocidad del caza y moverlo como en la pr�ctica 1.
	void update() override {};
};

