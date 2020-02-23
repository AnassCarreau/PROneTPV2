#include "AsteroidPool.h"
#include "ver_7/Collisions.h"
 void AsteroidPool::generateAsteroids(int n)
 {
	 for (int i = 0; i < n; i++)
	 {
		 Asteroid* o = ast_.getObj();
		 if (o!=nullptr)
		 {
			 o->isUse(true);
			 RandomNumberGenerator* r= game_->getRandGen();
			 int px, py, m, rx, ry, g, wh;
			 px = r->nextInt(0, game_->getWindowWidth());
			 py = r->nextInt(0, game_->getWindowWidth());
			 m = r->nextInt(1,10);
			 rx = r->nextInt(-50, 50);
			 ry = r->nextInt(-50, 50);
			 g = r->nextInt(1, 3);
			 wh = 10 + 3 * g;
			 Vector2D pos = Vector2D(px, py);
			 o->setPos(pos);
			 Vector2D c = Vector2D((game_->getWindowWidth() / 2) + rx, (game_->getWindowHeight() / 2) + ry);
			 Vector2D vel = (c - pos).normalize() * (m / 10.0);
			 o->setVel(vel);
			 o->setGenerations(g);
			 o->setWH(wh, wh);
			 astAct++;
		 }
	 }
 }

 void AsteroidPool::disablAll() {
	 //deactivate all the asteroids
	 for (auto& o : ast_.getPool())
	 {
		 o->isUse(false);
	 }
 }

 void AsteroidPool::onCollision(Asteroid* a, Bullet* b) {
		 if (a->getGenerations() > 0) {
			 Asteroid* astdiv1 = ast_.getObj();
			 Asteroid* astdiv2 = ast_.getObj();

			 Vector2D v = a->getVel().rotate(a->getRot() *45); //posible cambio de a->getRot()
			 Vector2D p = a->getPos() + v.normalize();

			 int wh = 10 + 3 * (a->getGenerations() - 1);
			 astdiv1->setVel(v);
			 astdiv1->setPos(p);
			 astdiv1->setGenerations(a->getGenerations() - 1);
			 astdiv1->setWH(wh, wh);
			 astdiv2->setVel(v);
			 astdiv2->setPos(p);
			 astdiv2->setGenerations(a->getGenerations() - 1);
			 astdiv2->setWH(wh, wh);
		 }
		 a->isUse(false);
		 astAct++;
 }
 