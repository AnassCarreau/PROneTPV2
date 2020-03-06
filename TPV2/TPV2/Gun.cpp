#include "Gun.h"

Gun::~Gun() {

}
void Gun::update()
{
	InputHandler* ih = InputHandler::instance();

	 
		if (ih->isKeyDown(SDLK_SPACE))
		{


			if (disparo)
			{
				//balasowey
				cout << "balasowey";
				Vector2D pos = tr_->getPos() + Vector2D(tr_->getW() / 2, tr_->getH() / 2) + Vector2D(0, -(tr_->getH() / 2 + 5.0)).rotate(tr_->getRot());
				Vector2D vel = Vector2D(0, -1).rotate(tr_->getRot()) * 2;
				bala->shoot(pos, vel, 10, 10);

				frame = game_->getTime() + shoot;
				disparo = false;
			}
		}
		else if (frame <= game_->getTime())
		{
			if (!disparo)
			{
				disparo = true;
				cout << "dispara";
			}
		}
	
}