#include "FighterCtrl.h"
#include "InputHandler.h"
#include "Entity.h"

FighterCtrl::FighterCtrl() :
	FighterCtrl(SDLK_UP, SDLK_RIGHT, SDLK_LEFT) {
}

FighterCtrl::FighterCtrl(SDL_Keycode up, SDL_Keycode right, SDL_Keycode left) :
	Component(ecs::FighterCtrl), //
	up_(up), //
	right_(right), //
	left_(left),
	tr_(nullptr)//
{
	
}



void FighterCtrl::init() {
	tr_ = GETCMP1_(Transform);
}

void FighterCtrl::update() {

	InputHandler* ih = InputHandler::instance();

	if (ih->keyDownEvent()) {
		if (ih->isKeyDown(up_)) {
			Vector2D newvel = tr_->getVel() + Vector2D(0, -1).rotate(tr_->getRot()) * 0.5;
			if (newvel.getX()>2 && newvel.getY()>2)
			{
				newvel = newvel.normalize() * 2;

				
			}
			tr_->setVel( newvel);
		
		}
		else if (ih->isKeyDown(right_)) {
			tr_->setRot(tr_->getRot() + 5);


		}
		else if (ih->isKeyDown(left_)) {
			tr_->setRot(tr_->getRot() -5);
		}
		
	}
}