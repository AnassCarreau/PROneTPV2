#include "FighterMotion.h"
//void FighterMotion::init() {
//	naveDelKibab = GETCMP1_(Transform);
//}

void FighterMotion::update() {
	
	naveDelKibab->setPos(naveDelKibab->getPos() + naveDelKibab->getVel());
	naveDelKibab->setVel(naveDelKibab->getVel() * 0.995);
	if (naveDelKibab->getPos().getX() +naveDelKibab->getH() >= game_->getWindowWidth()
		|| naveDelKibab->getPos().getX() <= 0 
		|| naveDelKibab->getPos().getY() + naveDelKibab->getH() >= game_->getWindowHeight()
		|| naveDelKibab->getPos().getY() <= 0)
	{
		std::cout<<  "jebab";
		naveDelKibab->setVel(naveDelKibab->getVel() * -1);
	}
}

void FighterMotion::init() {
	naveDelKibab = GETCMP2_(ecs::Transform,Transform);
}
