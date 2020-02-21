#include "BulletsPool.h"


void BulletsPool::onCollision(Bullet* b, Asteroid* a) {
	b->isUse(false);
}