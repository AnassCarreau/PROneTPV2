#pragma once
#include "System.h"
#include "Entity.h"

class AsteroidsSystem : public System {
public:
	// - añadir n asteroides al juego como en la práctica 1 pero usando entidades.
	// - no olvidar añadir los asteroides al grupo _grp_Asteroid.
	void addAsteroids(int n) {};

	// - desactivar el asteroide “a” y crear 2 asteroides como en la práctica 1.
	void onCollisionWithBullet(Entity* a, Entity* b) {};
	// - si el juego está parado no hacer nada.
	// - mover los asteroides como en la práctica 1.
	void update() override {};
private:
	std::size_t numOfAsteroids_;
};