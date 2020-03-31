#include "FighterMotion.h"

#include "Entity.h"

FighterMotion::FighterMotion() : Component(ecs::FighterMotion), tr_(nullptr) {
}

FighterMotion::~FighterMotion() {
}

void FighterMotion::init() {
	tr_ = GETCMP1_(Transform);
}

void FighterMotion::update() {

	tr_->setVel(tr_->getVel() * 0.995); //Desaceleración

	Vector2D newPos = tr_->getPos() + tr_->getVel(); //Calculamos a nueva posición
	double y = newPos.getY();
	double x = newPos.getX();

	if (y <= 0 || y >= game_->getWindowHeight() - tr_->getH()) { //Comprobamos con los límites horizontales para el rebote
		newPos.setY(y);
		tr_->setVelY(-tr_->getVel().getY());
	}
	if (x <= 0 || x >= game_->getWindowWidth() - tr_->getW()) { //Comprobamos con los límites verticales para el rebote
		newPos.setX(x);
		tr_->setVelX(-tr_->getVel().getX());
	}

	tr_->setPos(newPos);
}

