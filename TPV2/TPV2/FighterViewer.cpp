#include "FighterViewer.h"

FighterViewer::FighterViewer(Texture* fig) :
	Component(ecs::FighterViewer) ,
	fighter ( fig),
	tr_(nullptr){
	clip.x = 47;
	clip.y = 90;
	clip.w = 207;
	clip.h = 250;
	destRect.x = 100;
	destRect.w = 100;
	destRect.h = 100;
	destRect.y = 100;
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {
	fighter->render(destRect, 0, clip);
	
}

void FighterViewer::init() {
	tr_ = GETCMP1_(Transform);
}