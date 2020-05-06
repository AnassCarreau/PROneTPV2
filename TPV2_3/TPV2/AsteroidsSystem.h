#pragma once
#include "Transform.h"
#include "Manager.h"
#include "GameState.h"
#include "AsteroidPool.h"
#include "checkML.h"

class AsteroidsSystem : public System {
public:
	AsteroidsSystem() :
		numOfAsteroids_(0)//
	{}
	// - añadir n asteroides al juego como en la práctica 1 pero usando entidades.
	// - no olvidar añadir los asteroides al grupo _grp_Asteroid.
	void addAsteroids(int n) {
		numOfAsteroids_=0;
		for (int i = 0; i < n; i++)
		{
			int px = game_->getRandGen()->nextInt(0, game_->getWindowWidth());
			int py= game_->getRandGen()->nextInt(0, game_->getWindowHeight());
			Vector2D pos = Vector2D(px, py);
			int rx = game_->getRandGen()->nextInt(-50,50);
			int ry = game_->getRandGen()->nextInt(-50, 50);
			int m = game_->getRandGen()->nextInt(1, 10);
			Vector2D c = Vector2D((game_->getWindowWidth() / 2.0) + rx, (game_->getWindowHeight() / 2.0) + ry);
			Vector2D vel = (c - pos).normalize() * (m / 10.0);
			int g = game_->getRandGen()->nextInt(1, 3);
			int w =10+3*g;
			int h = w;

			Entity* e=  mngr_->addEntity<AsteroidPool>(pos, vel,w, h, g);
			if (e != nullptr)
				e->addToGroup<_grp_Asteroid>();
			numOfAsteroids_++;
		}
	};

	// - desactivar el asteroide “a” y crear 2 asteroides como en la práctica 1.
	void onCollisionWithBullet(Entity* a, Entity* b) {

		game_->getAudioMngr()->playChannel(Resources::Explosion, 0, 1);
		a->setActive(false);
		numOfAsteroids_--;
		int gen = a->getComponent<AsteroidLifeTime>()->generaciones_;
		if (gen > 0) {
			gen--;
			Transform* astd = a->getComponent<Transform>();
			Vector2D v, p;
			for (int i = 0; i < 2; i++) {
				v = astd->velocity_.rotate(i * 45.0);
				p = astd->position_ + v.normalize();
				int tam = 10 + 3 * gen;
				Entity* e = mngr_->addEntity<AsteroidPool>(p, v, tam, tam, gen);
				if (e != nullptr)
				{
					e->addToGroup<_grp_Asteroid>();
					e->setActive(true);
					numOfAsteroids_++;
				}

			}
		}
		else if (numOfAsteroids_ == 0)
		{
			SinAsteroides();
		}
	};
	void SinAsteroides();
	// - si el juego está parado no hacer nada.
	// - mover los asteroides como en la práctica 1.
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->Play)
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