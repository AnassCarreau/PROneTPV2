#include "FighterViewer.h"

FighterViewer::FighterViewer(Texture* fig) :
	Component(ecs::FighterViewer) ,
	fighter ( fig),
	tr_(nullptr){
	clip.x = 47;
	clip.y = 90;
	clip.w = 207;
	clip.h = 250;
	destRect.w = 50;
	destRect.h = 50;
	
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {
	destRect.x = tr_->getPos().getX();
	destRect.y = tr_->getPos().getY();
	fighter->render(destRect, tr_->getRot(), clip);
	
}

void FighterViewer::init() {
	tr_ = GETCMP1_(Transform);
	
}