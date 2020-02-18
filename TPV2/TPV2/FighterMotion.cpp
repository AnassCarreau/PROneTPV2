#include "FighterMotion.h"

//void FighterMotion::init() {
//	naveDelKibab = GETCMP1_(Transform);
//}

void FighterMotion::update() {
	
	naveDelKibab->setPos(naveDelKibab->getPos() + naveDelKibab->getVel());
	naveDelKibab->setVel(naveDelKibab->getVel() * 0.995);
	if (naveDelKibab->getPos().getX() >= game_->getWindowWidth()
		|| naveDelKibab->getPos().getX() <= 0 
		|| naveDelKibab->getPos().getY() >= game_->getWindowHeight() 
		|| naveDelKibab->getPos().getY() <= 0)
	{
		naveDelKibab->setVel(naveDelKibab->getVel() * -1);
	}
}
