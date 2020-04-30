#pragma once
#include "Entity.h"
#include "ObjectPool.h"
#include "Singleton.h"
#include "checkML.h"
#include "ImageComponent.h"

class BulletsPool : public Singleton<BulletsPool>
{
	friend Singleton<BulletsPool>;
private:

	BulletsPool() : BulletsPool(10) {};
	BulletsPool(std::size_t n) :
		bul(n) {
		for (Entity* e : bul.getPool()) {
			e->addComponent<Transform>();
			e->addComponent<ImageComponent>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Bullet));
		}
	}
	ObjectPool<Entity>bul;
public:

	virtual ~BulletsPool() {}
	
	template<typename ...Targs>
	inline static Entity* construct(Targs&& ...args) {
		return BulletsPool::instance()->construct_(std::forward<Targs>(args)...);
	}

	inline static void destroy(Entity* p) {
		BulletsPool::instance()->destroy_(p);
	}

	inline Entity* construct_(Vector2D pos, Vector2D vel, double width, double height) {
		Entity* e = bul.getObj();
		if (e != nullptr) {
			e->setActive(true);
			Transform* tr = e->getComponent<Transform>();
			tr->position_.set(pos);
			tr->velocity_.set(vel);
			tr->width_ = width;
			tr->height_ = height;

			//game_->getAudioMngr()->playChannel(Resources::Gun_Shoot, 0);

		}
		return e;
	}

	inline void destroy_(Entity* p) {
		bul.relObj(p);
	}

	void disableAll() {
		//deactivate all the bullets
		for (auto& o : bul.getPool())
		{
			o->setActive(false);
		}
	}
};

