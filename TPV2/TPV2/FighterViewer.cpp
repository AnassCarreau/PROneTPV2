#include "FighterViewer.h"

FighterViewer::FighterViewer() : Component(ecs::FighterViewer) {
	fighter = game_->getTextureMngr()->getTexture(6);
}

FighterViewer::~FighterViewer() {

}

void FighterViewer::draw() {

}