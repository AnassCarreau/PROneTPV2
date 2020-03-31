#include "Heart.h"

Heart::Heart(Texture* image) : image_(image), Component::Component(ecs::Heart) {
}

Heart::~Heart() {
}

void Heart::init() {
}

void Heart::draw() {
	SDL_Rect destRect; //Primer rectángulo que se va a dibujar
	destRect.x = HEART_W_H * 0.5; destRect.y = HEART_W_H * 0.5;
	destRect.w = HEART_W_H; destRect.h = HEART_W_H;

	for (int i = 0; i < hearts; i++) {
		image_->render(destRect);
		destRect.x += HEART_W_H * 1.5;
	}
}

void Heart::loseHeart() {
	hearts--;
}

void Heart::resetHeart() {
	hearts = 3;
}