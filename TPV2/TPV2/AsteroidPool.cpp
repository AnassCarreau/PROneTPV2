#include "AsteroidPool.h"

 void AsteroidPool::generateAsteroids(int n)
 {
	 for (int i = 0; i < n; i++)
	 {
		 Asteroid* o = ast.getObj();
		 if (o!=nullptr)
		 {
			 //o->setInUse(true);
			 RandomNumberGenerator* r= game_->getRandGen();
			 int x, y, w;
			 x = r->nextInt(0, game_->getWindowWidth());
			 y = r->nextInt(0, game_->getWindowWidth());
			 w = r->nextInt(0,10);
			 o->setPos(Vector2D(x, y));
			 o->setWH(w,w);
		 }
	 }
 }