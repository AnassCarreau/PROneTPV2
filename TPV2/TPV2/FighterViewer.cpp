#include "FighterViewer.h"

FighterViewer::FighterViewer() : Component(ecs::FighterViewer) {
	fighter = game_->getTextureMngr()->getTexture(6);
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {
	SDL_Rect clip,destRect;
	clip.x= 47;
	clip.y = 90;
	clip.w = 207;
	clip.h = 250;
	destRect.x= 640 / 2;
	destRect.y = 680 / 2;
	fighter->render(destRect, 0, clip);
}