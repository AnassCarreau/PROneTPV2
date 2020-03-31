#include "FighterCtrl.h"
#include "InputHandler.h"
#include "Entity.h"
#include "Transform.h"

FighterCtrl::FighterCtrl() :
		FighterCtrl(SDLK_UP, SDLK_DOWN, SDLK_SPACE) {
}

FighterCtrl::FighterCtrl(SDL_Keycode up, SDL_Keycode left, SDL_Keycode right) :
		Component(ecs::FighterCtrl), up_(up), left_(left), right_(right), tr_(nullptr) {}

FighterCtrl::~FighterCtrl() {}

void FighterCtrl::init() {
	tr_ = GETCMP1_(Transform);
}

void FighterCtrl::update() {

	InputHandler *ih = InputHandler::instance();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(up_)) {
			//Asigna a la velocidad la misma dirección en la que mira el caza
			Vector2D newVel = tr_->getVel() + Vector2D(0, -1).rotate(tr_->getRot()) * 0.5; 
			if (newVel.magnitude() >= speedLimit.magnitude()) newVel.normalize() * speedLimit;
			tr_->setVel(newVel);
		} else if (ih->isKeyDown(left_)) {
			tr_->setRot(tr_->getRot() - 5);
		} else if (ih->isKeyDown(right_)) {
			tr_->setRot(tr_->getRot() + 5);
		}

	}
}

