#pragma once
#include "ver_7/Component.h"
#include "ver_7/ObjectPool.h"
#include"Asteroid.h"
#include "Bullet.h"

class AsteroidPool:public Component
{
	ObjectPool<Asteroid, 30>ast_;
	AsteroidPool* joder;
	Asteroid tupm;
	int astAct = 0;
	public :
		/*AsteroidPool() : Component(ecs::AsteroidPool),
			joder([](Asteroid*o)
			 {
		

			return o->isUse(true); };*/
		
		void  generateAsteroids(int n);	

		void disablAll();
		void  onCollision(Asteroid* a, Bullet* b);
		int getNumOfAsteroid() { return astAct; }

		vector<Asteroid*> getPool()
		{
			return ast.getPool();
		}
};

