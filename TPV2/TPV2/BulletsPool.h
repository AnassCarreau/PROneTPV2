#pragma once
#include "ObjectPool.h"
#include "Bullet.h"
#include "Component.h"
#include "Asteroid.h"
class BulletsPool:public Component
{
private:
	  ObjectPool<Bullet,10>bull;
public:
	BulletsPool() : Component(ecs::BulletsPool), bull([](Bullet* a) {return a->isInUse(); }) {};
	virtual ~BulletsPool() {};
	void  shoot(Vector2D pos, Vector2D vel, double w, double h)
	{
		  Bullet* b = bull.getObj();
		  b->isUse(true);
		  b->setPos(pos);
		  b->setVel(vel);
		  b->setWH(w, h);
		  game_->getAudioMngr()->playChannel(Resources::Gun_Shoot, 0);
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

