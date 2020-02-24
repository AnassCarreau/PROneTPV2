#pragma once
#include "ver_7/ObjectPool.h"
#include "Bullet.h"
#include "Asteroid.h" 
#include "ver_7/Component.h"
class BulletsPool:public Component
{
private:
	  ObjectPool<Bullet,10>bull;

public:
	BulletsPool() : Component(ecs::BulletsPool), bull([](Bullet* a) {return a->isInUse(); }) {};
	void  shoot(Vector2D pos, Vector2D vel, double w, double h)
	  {
		  //bull = new Bullet( pos,  vel,  w,  h, 0.0);
	  };

	  void  disablAll()
	  {

		  for (auto& o : bull.getPool())
		  {
			  o->isUse(false);
		  }
	  };
	  void onCollision(Bullet* b, Asteroid* a);
	  vector<Bullet*> getPool()
	  {
		  return bull.getPool();
	  }
		  ;
};

