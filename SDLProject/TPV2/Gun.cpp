#include "Gun.h"

Gun::Gun(SDL_Keycode space, BulletsPool* bulletsPool) : space_(space), bulletsPool_(bulletsPool), Component(ecs::Gun) {}

void Gun::init() {
	tr_ = GETCMP1_(Transform);
}

void Gun::update() {
	InputHandler* ih = InputHandler::instance();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(space_) && SDL_GetTicks() - tick >= timeShoot_) {
			Vector2D p = tr_->getPos();
			int w = tr_->getW(); int h = tr_->getH();
			double r = tr_->getRot();
			Vector2D bulletPos = p + Vector2D(w / 2, h / 2) + Vector2D(0, -(h / 2 + 5.0)).rotate(r);
			Vector2D bulletVel = Vector2D(0, -1).rotate(r) * 2;

			bulletsPool_->shoot(bulletPos, bulletVel, BULLET_W, BULLET_H);
			game_->getAudioMngr()->playChannel(Resources::GunShot, 0);
			tick = SDL_GetTicks();
		}
	}
}