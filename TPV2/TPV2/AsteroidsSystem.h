#pragma once
#include "System.h"
#include "Entity.h"
#include "ScoreManager.h"
#include "Transform.h"
#include "Manager.h"
class AsteroidsSystem : public System {
public:
	// - a�adir n asteroides al juego como en la pr�ctica 1 pero usando entidades.
	// - no olvidar a�adir los asteroides al grupo _grp_Asteroid.
	int numAsteroids() { return numOfAsteroids_; }
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

	// - desactivar el asteroide �a� y crear 2 asteroides como en la pr�ctica 1.
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
	// - si el juego est� parado no hacer nada.
	// - mover los asteroides como en la pr�ctica 1.
	void update() override {
		//mngr_->getHandler<_hdlr_GameState>();
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->jugando)
		{
			for (auto& o : mngr_->getGroupEntities<_grp_Asteroid>())
			{
				if (!o->isActive())
					return;
				Transform* tr = o->getComponent<Transform>();
				tr->position_ = tr->position_ + tr->velocity_;
				tr->rotation_ = tr->rotation_ + 0.5;
				if (tr->position_.getX() > game_->getWindowWidth())
				{
					tr->position_.setX(0);
				}
				else  if (tr->position_.getY() > game_->getWindowHeight())
				{
					tr->position_.setY(0);
				}
				else if (tr->position_.getX() < 0)
				{
					tr->position_.setX((game_->getWindowWidth()));
				}
				else  if (tr->position_.getY() < 0)
				{
					tr->position_.setY((game_->getWindowHeight()));
				}
			}
		}
	
	};
private:
	std::size_t numOfAsteroids_;
};