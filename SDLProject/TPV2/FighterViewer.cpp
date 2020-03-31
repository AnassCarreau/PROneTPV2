#include "FighterViewer.h".

FighterViewer::FighterViewer(Texture* image) : image_(image), tr_(nullptr), Component(ecs::FighterViewer){
}

void FighterViewer::init() {
	tr_ = GETCMP1_(Transform);
}

void FighterViewer::draw() {
	SDL_Rect destRect RECT(tr_->getPos().getX(), tr_->getPos().getY(), tr_->getW(), tr_->getH());

	image_->render(destRect, tr_->getRot(), { 800, 90, 320, 250 });
}