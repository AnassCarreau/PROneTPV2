#include "FighterViewer.h"

FighterViewer::FighterViewer() : Component(ecs::FighterViewer) {
	fighter = game_->getTextureMngr()->getTexture(Resources::Airplanes);
	clip.x = 47;
	clip.y = 90;
	clip.w = 207;
	clip.h = 250;
	destRect.x = game_->getWindowWidth() / 2;
	destRect.y = game_->getWindowHeight() / 2;
	tr_ = GETCMP1_(Transform);
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {
	fighter->render(destRect, 0, clip);
}