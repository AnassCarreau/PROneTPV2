#include "FighterCtrl.h"
#include "ver_7/InputHandler.h"
#include "ver_7/Entity.h"

FighterCtrl::FighterCtrl() :
	FighterCtrl(SDLK_UP, SDLK_RIGHT, SDLK_LEFT) {
}

FighterCtrl::FighterCtrl(SDL_Keycode up, SDL_Keycode right, SDL_Keycode left) :
	Component(ecs::FighterCtrl), //
	up_(up), //
	right_(right), //
	left_(left),
	tr_(nullptr)//
{}

FighterCtrl::~FighterCtrl() {

}

void FighterCtrl::init() {
	tr_ = GETCMP1_(Transform);
}

void FighterCtrl::update() {

	InputHandler* ih = InputHandler::instance();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(up_)) {
			tr_->setVelX(tr_->getPos().getX() + tr_->getRot());
			tr_->setVelY(tr_->getPos().getY() + tr_->getRot());
		}
		else if (ih->isKeyDown(right_)) {
			tr_->setRot(tr_->getRot() + 5);

		}
		else if (ih->isKeyDown(left_)) {
			tr_->setRot(tr_->getRot() - 5);
		}
	}
}