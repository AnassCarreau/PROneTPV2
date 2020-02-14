#include "PaddleKBCtrl.h"
#include "InputHandler.h"
#include "Entity.h"
#include "Transform.h"

PaddleKBCtrl::PaddleKBCtrl() :
		PaddleKBCtrl(SDLK_UP, SDLK_RIGHT,SDLK_LEFT, SDLK_SPACE) {
}

PaddleKBCtrl::PaddleKBCtrl(SDL_Keycode up, SDL_Keycode right, SDL_Keycode left, SDL_Keycode space):
Component(ecs::PaddleKBCtrl), //
		up_(up), //
		right_(right), //
		left_(left),
		tr_(nullptr)//
{}

PaddleKBCtrl::~PaddleKBCtrl() {
}

void PaddleKBCtrl::init() {
	tr_ = GETCMP1_(Transform);
}

void PaddleKBCtrl::update() {

	InputHandler *ih = InputHandler::instance();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(up_)) {
			tr_->setVelX(tr_->getPos().getX() + tr_->getRot()) ;
			tr_->setVelY(tr_->getPos().getY() + tr_->getRot()) ;
		} else if (ih->isKeyDown(right_)) {
			tr_->setRot(tr_->getRot() + 5);
			
		} else if (ih->isKeyDown(left_)) {
			tr_->setRot(tr_->getRot() - 5);
		}
		

	}
}

