#include "BulletsViewer.h"

BulletsViewer::BulletsViewer(Texture* image) : image_(image), Component(ecs::BulletsViewer) {}

BulletsViewer::~BulletsViewer() {}

void BulletsViewer::init() {
	pool_ = GETCMP1_(BulletsPool);
}

void BulletsViewer::draw() {
	for (auto bullet : pool_->getPool()) {
		if (bullet->inUse()) {
			SDL_Rect bulletRect;
			bulletRect.x = bullet->getPos().getX(); bulletRect.y = bullet->getPos().getY();
			bulletRect.w = bullet->getW(); bulletRect.h = bullet->getH();

			image_->render(bulletRect, bullet->getRotation());
		}
	}
}