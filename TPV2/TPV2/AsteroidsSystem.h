#pragma once
#include "System.h"
#include "Entity.h"
#include "ScoreManager.h"

class AsteroidsSystem : public System {
public:
	// - añadir n asteroides al juego como en la práctica 1 pero usando entidades.
	// - no olvidar añadir los asteroides al grupo _grp_Asteroid.
	void addAsteroids(int n) {
		for (int i = 0; i < n; i++)
		{
			int x = game_->getRandGen()->nextInt(0, game_->getWindowWidth());
			int y = game_->getRandGen()->nextInt(0, game_->getWindowHeight());
			int w = game_->getRandGen()->nextInt(25, 50);
			int h = w;
			int r = game_->getRandGen()->nextInt(1, 2);
			Uint32 lt = game_->getRandGen()->nextInt(5, 10);

			Entity* e = mngr_->addEntity<AsteroidPool>(x, y, w, h, r, lt);
			if (e != nullptr)
				e->addToGroup<_grp_Asteroid>();
		}
	};

	// - desactivar el asteroide “a” y crear 2 asteroides como en la práctica 1.
	void onCollisionWithBullet(Entity* a, Entity* b) {
		a->setActive(false);
		numOfAsteroids_--;
		if (a->getComponent<Asteroid>()->getGenerations() > 0) {
			int gen = a->getComponent<Asteroid>()->getGenerations() - 1;
			for (int i = 0; i < 2; i++) {
				Asteroid* astdiv = a->getComponent<Asteroid>();
				Transform* astd = a->getComponent<Transform>();
				astdiv->isUse(true);

				Vector2D v = a->getComponent<Transform>()->velocity_.rotate(i * 45);
				Vector2D p = a->getComponent<Transform>()->position_ + v.normalize();

				int wh = 10 + 3 * gen;
				astd->velocity_ = v;
				astd->position_ = p;
				astdiv->setGenerations(gen);
				astd->width_ = wh;
				astd->height_ = wh;

				numOfAsteroids_++;
			}
		}
	};
	// - si el juego está parado no hacer nada.
	// - mover los asteroides como en la práctica 1.
	void update() override {
		if (!scoreManager_->getPause()) {
			for (auto& o : ast->getPool())
			{
				o->setPos(o->getPos() + o->getVel());
				o->setRot(o->getRot() + 0.5);
				if (o->getPos().getX() > game_->getWindowWidth())
				{
					o->setPosX(0);
				}
				else  if (o->getPos().getY() > game_->getWindowHeight())
				{
					o->setPosY(0);
				}
				else if (o->getPos().getX() < 0)
				{
					o->setPosX(game_->getWindowWidth());
				}
				else  if (o->getPos().getY() < 0)
				{
					o->setPosY(game_->getWindowHeight());
				}
			}
		}
	};
private:
	std::size_t numOfAsteroids_;
	ScoreManager* scoreManager_;
};