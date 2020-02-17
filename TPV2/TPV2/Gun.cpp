#include "Gun.h"

Gun::~Gun() {

}

void Gun::canshoot() {
	if (disparo && SDLK_SPACE)
	{
		//balasowey
		//shoot() de bulletspool
		frame = game_->getTime() + shoot;
		disparo = false;
	}
	else if (! disparo && frame <= game_->getTime())
	{
		disparo = true;
	}
}