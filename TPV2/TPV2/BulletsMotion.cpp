#include "BulletsMotion.h"

 void BulletsMotion ::update()
{
	 balKibab->setPos(balKibab->getPos() + balKibab->getVel());
	 if (balKibab->getPos().getX() >= game_->getWindowWidth()
		 || balKibab->getPos().getX() <= 0
		 || balKibab->getPos().getY() >= game_->getWindowHeight()
		 || balKibab->getPos().getY() <= 0)
	 {

		 //bala sin uso 
		 //marcar bala  como no usada 
	 }

}