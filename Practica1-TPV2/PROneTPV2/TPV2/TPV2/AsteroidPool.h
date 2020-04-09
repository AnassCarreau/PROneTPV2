#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include"Asteroid.h"
#include "checkML.h"
#include "Bullet.h"

class AsteroidPool:public Component
{
	ObjectPool<Asteroid,30>ast;
	
	int astAct = 0;
	public :
		AsteroidPool() :  Component(ecs::AsteroidPool),ast([](Asteroid* a) {return a->isInUse();}) {};
		virtual ~AsteroidPool() {};
		void  generateAsteroids(int n);	
		
		void disablAll();
		void  onCollision(Asteroid* a, Bullet* b);
		int getNumOfAsteroid() { return astAct; }

		const vector<Asteroid*>& getPool()
		{
			return ast.getPool();
		}
};

