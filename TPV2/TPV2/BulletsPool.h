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
class BulletsPool : public Singleton<BulletsPool>
{
	friend Singleton<BulletsPool>;
private:
	BulletsPool() : BulletsPool(10) {};
	BulletsPool(std::size_t n) :
		bul(n) {
		for (Entity* e : bul.getPool()) {
			e->addComponent<Transform>();
			e->addComponent<Bullet>();
			e->addComponent<ImageComponent>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Bullet));
		}
	}
	ObjectPool<Entity>bul;
public:
	
	void  shoot(Vector2D pos, Vector2D vel, double w, double h)
	{
		//mngr_->addEntity<Bullet>();
		construct_(pos, vel, w, h);
	};
	
	virtual ~BulletsPool() {
	}

	template<typename ...Targs>
	inline static Entity* construct(Targs&& ...args) {
		return BulletsPool::instance()->construct_(std::forward<Targs>(args)...);
	}

	inline static void destroy(Entity* p) {
		BulletsPool::instance()->destroy_(p);
	}
	/*
	  vector<Bullet*> getPool()
	  {
		  return bull.getPool();
	  }
		  ;*/
	inline Entity* construct_(Vector2D pos, Vector2D vel, double width, double height) {
		Entity* e = bul.getObj();
		if (e != nullptr) {
			e->setActive(true);
			Transform* tr = e->getComponent<Transform>();
			tr->position_.set(pos);
			tr->velocity_.set(vel);
			tr->width_ = width;
			tr->height_ = height;
			Bullet* as = e->getComponent<Bullet>();
			as->isUse(true);
			//game_->getAudioMngr()->playChannel(Resources::Gun_Shoot, 0);

		}
		return e;
	}

	inline void destroy_(Entity* p) {
		bul.relObj(p);
	}

	void onCollision(Bullet* b, Asteroid* a) {
		b->isUse(false);
	}
};

