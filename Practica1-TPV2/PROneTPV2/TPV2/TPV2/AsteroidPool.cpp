#include "AsteroidPool.h"
#include "Collisions.h"
 void AsteroidPool::generateAsteroids(int n)
 {
	 for (int i = 0; i < n; i++)
	 {
		 Asteroid* o = ast.getObj();
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
	 for (auto& o : ast.getPool())
	 {
		 o->isUse(false);
		 
	 }
	 astAct = 0;
 }

 void AsteroidPool::onCollision(Asteroid* a, Bullet* b) {
	
	 astAct--;
	 game_->getAudioMngr()->playChannel(Resources::Explosion, 0);

		 if (a->getGenerations() > 0) {
			 int gen = a->getGenerations() - 1;
			 for (int i = 0; i < 2; i++) {
				 Asteroid* astdiv = ast.getObj();
				 if (astdiv != nullptr) {
					 astdiv->isUse(true);

					 Vector2D v = a->getVel().rotate(i * 45);
					 Vector2D p = a->getPos() + v.normalize();

					 int wh = 10 + 3 * gen;
					 astdiv->setVel(v);
					 astdiv->setPos(p);
					 astdiv->setGenerations(gen);
					 astdiv->setWH(wh, wh);

					 astAct++;
				 }
			 }
		 }
		 a->isUse(false);
 }
 