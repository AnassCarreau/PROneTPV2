#pragma once
#include "Component.h"
#include "ObjectPool.h"
#include"Asteroid.h"
#include "Bullet.h"

class AsteroidPool:public Component
{
	ObjectPool<Asteroid,30>ast;
	
	int astAct = 0;
	public :
		AsteroidPool() :  Component(ecs::AsteroidPool),ast([](Asteroid* a) {return a->isInUse();}) {};
		virtual ~AsteroidPool() {
			for (int i = 0; i < 30; i++) {
				 
			}
		}
		void  generateAsteroids(int n);	
		
		void disablAll();
		void  onCollision(Asteroid* a, Bullet* b);
		int getNumOfAsteroid() { return astAct; }

		vector<Asteroid*> getPool()
		{
			return ast.getPool();
		}
};

