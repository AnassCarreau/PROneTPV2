#include "Gun.h"

Gun::~Gun() {

}

void Gun::canshoot() {

	InputHandler* ih = InputHandler::instance();

	
	if (ih->keyDownEvent() && disparo && ih->isKeyDown(SDLK_SPACE))
	{
		//balasowey
		bala->shoot(tr_->getPos(),tr_->getVel(),50,50);
		frame = game_->getTime() + shoot;
		disparo = false;
	}
	else if (! disparo && frame <= game_->getTime())
	{
		disparo = true;
	}
}