#pragma once
#include "System.h"
#include "Entity.h"

class AsteroidsSystem : public System {
public:
	// - a�adir n asteroides al juego como en la pr�ctica 1 pero usando entidades.
	// - no olvidar a�adir los asteroides al grupo _grp_Asteroid.
	void addAsteroids(int n) {};

	// - desactivar el asteroide �a� y crear 2 asteroides como en la pr�ctica 1.
	void onCollisionWithBullet(Entity* a, Entity* b) {};
	// - si el juego est� parado no hacer nada.
	// - mover los asteroides como en la pr�ctica 1.
	void update() override {};
private:
	std::size_t numOfAsteroids_;
};