#include "AsteroidsMotion.h"

AsteroidsMotion::AsteroidsMotion(): Component(ecs::AsteroidMotion){
}

void AsteroidsMotion::init() {
	pool_ = GETCMP1_(AsteroidPool);
}

void AsteroidsMotion::update() {
	for (auto asteroid : pool_->getPool()) {
		if (asteroid->inUse()) {
			asteroid->asteroidMotion(); //Para mover el asteroide

			//Comprobando los límites de la ventana
			double posX = asteroid->getPos().getX();
			double posY = asteroid->getPos().getY();
			int width = asteroid->getW();
			int height = asteroid->getH();

			if (posX + width < 0) asteroid->setPos(Vector2D(game_->getWindowWidth(), posY));
			else if (posX > game_->getWindowWidth()) asteroid->setPos(Vector2D(-width, posY));
			else if (posY + height < 0) asteroid->setPos(Vector2D(posX, game_->getWindowHeight()));
			else if (posY > game_->getWindowHeight()) asteroid->setPos(Vector2D(posX, -height));
		}
	}
}