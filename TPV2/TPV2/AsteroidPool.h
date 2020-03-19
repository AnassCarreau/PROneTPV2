#pragma once
#include "ecs.h"
#include "Entity.h"
#include "ImageComponent.h"
#include "ObjectPool.h"
#include "Singleton.h"
#include "LifeTime.h"
#include "Rotation.h"
#include "Transform.h"
#include"Asteroid.h"
#include "Bullet.h"
#include "PacMan.h"
#include "System.h"
class AsteroidPool: public Singleton<AsteroidPool>
{
	friend Singleton<AsteroidPool>;
private:
	AsteroidPool() : AsteroidPool(30) {};
	AsteroidPool(std::size_t n) :
		ast(n) {
		for (Entity* e : ast.getPool()) {
			e->addComponent<Transform>();
			e->addComponent<Asteroid>();
			e->addComponent<Rotation>();
		//	e->addComponent<AsteroidLifeTime>();
			e->addComponent<ImageComponent>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Asteroid));
		}
	}
	ObjectPool<Entity>ast;
	
	int astAct = 0;
public :
		
		virtual ~AsteroidPool() {
		}

		/*void  generateAsteroids(int n);	*/

		template<typename ...Targs>
		inline static Entity* construct(Targs&& ...args) {
			return AsteroidPool::instance()->construct_(std::forward<Targs>(args)...);
		}

		inline static void destroy(Entity* p) {
			AsteroidPool::instance()->destroy_(p);
		}

		inline Entity* construct_(Vector2D pos, Vector2D vel, double width, double height, double r, int generations) {
			Entity* e = ast.getObj();
			if (e != nullptr) {
				e->setActive(true);
				Transform* tr = e->getComponent<Transform>();
				tr->position_.set(pos);
				tr->velocity_.set(vel);
				tr->width_ = width;
				tr->height_ = height;
				Asteroid* as = e->getComponent<Asteroid>();
				as->setGenerations(generations);
				as->isUse(true);
				e->getComponent<Rotation>()->rotation_ = r;
				astAct++;
			}
			return e;
		}

		inline void destroy_(Entity* p) {
			ast.relObj(p);
		}

		void disablAll();
		void  onCollision(Asteroid* a, Bullet* b);
		int getNumOfAsteroid() { return astAct; }
};

