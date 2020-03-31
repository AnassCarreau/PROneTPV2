#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include "AsteroidEntity.h"

class AsteroidPool : public Component
{
private:
	ObjectPool<AsteroidEntity, 40> asteroids_;
	int numOfAsteroids = 0;

public:
	AsteroidPool();
	~AsteroidPool();

	void generateAsteroids(int n); //Genera “ n ” asteroides con características aleatorias
	void disablAll(); //Desactiva todos los asteroides
	void onCollision(AsteroidEntity* b); //El asteroide baja de generación y si llega a 0 lo desactiva al chocar con una bala
	
	int getNumOfAsteroids() { return numOfAsteroids; }
	vector<AsteroidEntity*> getPool() { return asteroids_.getPool(); }
};

