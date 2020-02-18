#include "FighterViewer.h"

FighterViewer::FighterViewer(Texture* fig) : Component(ecs::FighterViewer) {
	fighter = fig;
	//fighter = game_->getTextureMngr()->getTexture(Resources::Airplanes);
	clip.x = 47;
	clip.y = 90;
	clip.w = 207;
	clip.h = 250;
	destRect.x = game_->getWindowWidth() / 2;
	destRect.y = game_->getWindowHeight() / 2;
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {
	fighter->render(destRect, 0, clip);
}

void FighterViewer::init() {
	tr_ = GETCMP1_(Transform);
}