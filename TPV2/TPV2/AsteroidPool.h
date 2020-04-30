#pragma once
#include "Entity.h"
#include "ObjectPool.h"
#include "Singleton.h"
#include "AsteroidLifeTime.h"
#include "checkML.h"

class AsteroidPool: public Singleton<AsteroidPool>
{
	friend Singleton<AsteroidPool>;
private:
	AsteroidPool() : AsteroidPool(30) {};
	AsteroidPool(std::size_t n) :
		ast(n) {
		for (Entity* e : ast.getPool()) {
			e->addComponent<Transform>();
		    e->addComponent<AsteroidLifeTime>();	
			e->addComponent<ImageComponent>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Asteroid));
		}
	}
	 ObjectPool<Entity>ast;
	
public :
		
		virtual ~AsteroidPool() {
		}


		template<typename ...Targs>
		inline static Entity* construct(Targs&& ...args) {
			return AsteroidPool::instance()->construct_(std::forward<Targs>(args)...);
		}

		inline static void destroy(Entity* p) {
			AsteroidPool::instance()->destroy_(p);
		}

		inline Entity* construct_(Vector2D pos, Vector2D vel, double width, double height, int generations) {
			Entity* e = ast.getObj();
			if (e != nullptr) {
				e->setActive(true);
				Transform* tr = e->getComponent<Transform>();
				tr->position_.set(pos);
				tr->velocity_.set(vel);
				tr->width_ = width;
				tr->height_ = height;
				e->getComponent<AsteroidLifeTime>()->generaciones_ = generations;
			}
			return e;
		}

		inline void destroy_(Entity* p) {
			ast.relObj(p);
		}

		void disableAll() {
			//desactiva todos los asteroides
			for (auto& o : ast.getPool())
			{
				o->setActive(false);
			}
		}
		
};

