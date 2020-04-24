#pragma once
#include "System.h"
#include "Entity.h"
#include "Transform.h"
#include "Manager.h"
#include "GameState.h"
#include "Health.h"
class FighterSystem : public System {
private:
	Transform* tr_;
	Entity* fighter;
public:
	// - poner el caza en el centro con velocidad 0 y rotación 0. No hace falta
	// desactivar la entidad (no dibujarla si el juego está parado en RenderSystem).
	void onCollisionWithAsteroid(Entity* a) {
		a->setActive(false);
		
		tr_->position_ = Vector2D(250, 250);
		tr_->rotation_ = 0;
	};
	// - crear la entidad del caza, añadir sus componentes (Transform, Health, etc.)
	// y asociarla con el handler _hndlr_Fighter.
	void init() override {
		fighter = mngr_->addEntity();
		tr_ = fighter->addComponent<Transform>(Vector2D(100.0, 100), Vector2D(),50, 50, 0);
		fighter->addComponent<ImageComponent>(game_->getTextureMngr()->getTexture(Resources::Airplanes));
		fighter->addComponent<Health>();
		mngr_->setHandler<_hdlr_Fighter>(fighter);
	};
		// - si el juego está parado no hacer nada.
		// - actualizar la velocidad del caza y moverlo como en la práctica 1.
	void update() override {
		
		//if el juego  esta parado no hacer nada
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();
		if (state->estado == state->jugando)
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
		}
		
	};
};


