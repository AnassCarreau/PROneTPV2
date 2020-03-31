#include "AsteroidsViewer.h"

AsteroidsViewer::AsteroidsViewer(Texture* image) : image_(image), Component(ecs::AsteroidViewer) {}

AsteroidsViewer::~AsteroidsViewer() {}

void AsteroidsViewer::init() {
	pool_ = GETCMP1_(AsteroidPool);
}

void AsteroidsViewer::draw() {
	for (auto asteroid : pool_->getPool()) {
		if (asteroid->inUse()) {
			SDL_Rect asteroidRect;
			asteroidRect.x = asteroid->getPos().getX(); asteroidRect.y = asteroid->getPos().getY();
			asteroidRect.w = asteroid->getW(); asteroidRect.h = asteroid->getH();
			 
			image_->render(asteroidRect, asteroid->getRotation());      
		}
	}
}