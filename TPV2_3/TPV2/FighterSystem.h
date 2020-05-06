#pragma once
#include "checkML.h"

class FighterSystem : public System {
private:
	Entity* fighter;
	Transform* tr_;
public:
	FighterSystem() :
		fighter(nullptr), //
		tr_(nullptr)
	{}
	// - crear la entidad del caza, añadir sus componentes (Transform, Health, etc.)
	// y asociarla con el handler _hndlr_Fighter.
	void init() override {
		fighter = mngr_->addEntity();
		tr_ = fighter->addComponent<Transform>(Vector2D(game_->getWindowWidth() / 2 - 25.0, game_->getWindowHeight() / 2 - 25.0), Vector2D(), 50, 50, 0);
		fighter->addComponent<ImageComponent>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
		fighter->addComponent<Health>();
		mngr_->setHandler<_hdlr_Fighter>(fighter);
	};
	// - poner el caza en el centro con velocidad 0 y rotación 0. No hace falta
	// desactivar la entidad (no dibujarla si el juego está parado en RenderSystem).
	void onCollisionWithAsteroid(Entity* a) {
		game_->getAudioMngr()->playMusic(Resources::Explosion, 0);

		tr_->position_ = Vector2D(game_->getWindowWidth() / 2 - 25.0, game_->getWindowHeight() / 2 - 25.0);
		tr_->velocity_ = Vector2D(0, 0);
		tr_->rotation_ = 0;
	};
	
	// - si el juego está parado no hacer nada.
	// - actualizar la velocidad del caza y moverlo como en la práctica 1.
	void update() override {
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->Play)
		{
			InputHandler* ih = InputHandler::instance();

			if (ih->keyDownEvent()) {
				if (ih->isKeyDown(SDLK_UP)) {
					Vector2D newvel = tr_->velocity_ + Vector2D(0, -1).rotate(tr_->rotation_) * 0.5;
					if ((newvel.getX() > 2 && newvel.getY() > 2)) {
						newvel = newvel.normalize() * 2;
					}
					tr_->velocity_ = newvel;
				}
				else if (ih->isKeyDown(SDLK_RIGHT)) {
					tr_->rotation_ = tr_->rotation_ + 5;
				}
				else if (ih->isKeyDown(SDLK_LEFT)) {
					tr_->rotation_ = tr_->rotation_ - 5;
				}
			}
			tr_->position_ = tr_->position_ + tr_->velocity_;
			tr_->velocity_ = tr_->velocity_ * 0.995;
			if (tr_->position_.getX() + tr_->width_ >= game_->getWindowWidth()
				|| tr_->position_.getX() <= 0
				|| tr_->position_.getY() + tr_->height_ >= game_->getWindowHeight()
				|| tr_->position_.getY() <= 0)
			{
				tr_->velocity_ = tr_->velocity_ * -1;
			}

		}

	};
};


