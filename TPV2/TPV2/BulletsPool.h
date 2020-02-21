#pragma once
#include "ver_7/ObjectPool.h"
#include "Bullet.h"
#include "Asteroid.h"
class BulletsPool
{
private:
	  ObjectPool<Bullet,10>bull;

public:
	//BulletsPool() { bull = nullptr; };
	  void  shoot(Vector2D pos, Vector2D vel, double w, double h)
	  {
		  //bull = new Bullet( pos,  vel,  w,  h, 0.0);
	  };
	  void  disablAll()
	  {
		/*  for (int i = 0; i < 10; i++) {
			  [](bull) { return bull->inUse(); }
		  }*/
	  };
	  void onCollision(Bullet* b, Asteroid* a);
	  vector<Bullet*> getPool()
	  {
		  return bull.getPool();
	  }
		  ;
};

