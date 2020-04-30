#pragma once
#include "ecs.h"
#include "Manager.h"
#include "ImageComponent.h"
#include "SDL_macros.h"
#include "SDLGame.h"
#include "System.h"
#include "Transform.h"
#include "Entity.h"
#include "Manager.h"
#include "Score.h"
#include "SDLGame.h"
#include "Texture.h"
#include "GameState.h"

class RenderSystem: public System {
public:
	void init()override
	{
		vidaTex = game_->getTextureMngr()->getTexture(Resources::Heart);
	}
	void update() override {
		drawScore();
		drawLifes();
		// draw Asteroids
		auto state = mngr_->getHandler<_hdlr_GameState>()->getComponent<GameState>();

		if (state->estado == state->Play)
		{
			for (auto& e : mngr_->getGroupEntities<_grp_Asteroid>()) {
				draw(e);
			}
			for (auto& a : mngr_->getGroupEntities<_grp_Bullet>()) {
				draw(a);
			}
			// draw fighter
			drawFighter(mngr_->getHandler<_hdlr_Fighter>());
		}
		else
		{

			string cadena;
			switch (state->estado)
			{
			case GameState::Start:
				cadena = "Presione cualquier tecla para empezar la partida";
				break;
			case GameState::Pause:
				cadena = "Upsss Has perdido una vida .Intentalo de nuevo";
				break;
			case GameState::FinishWin:
				cadena = "Has ganado eres el mejor";

				break;
			case GameState::FinishLose:
				cadena = "Eres un perdedor";

				break;

			}
			Texture msg(game_->getRenderer(), cadena, game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0xff0000ff) });
			msg.render(game_->getWindowWidth() / 2 - msg.getWidth() / 2, game_->getWindowHeight() - msg.getHeight() - 10);
		}

		
	}	
	void draw(Entity *e) {
		Transform *tr = e->getComponent<Transform>();
		ImageComponent *img = e->getComponent<ImageComponent>();		
		SDL_Rect dest =
			RECT(tr->position_.getX(), tr->position_.getY(), tr->width_,tr->height_);
		img->tex_->render(dest, tr->rotation_);
		
	}
	void drawFighter(Entity* e) {
		Transform* tr = e->getComponent<Transform>();
		ImageComponent* img = e->getComponent<ImageComponent>();
		SDL_Rect clip;
		clip.x = 47;
		clip.y = 90;
		clip.w = 207;
		clip.h = 250;
		SDL_Rect dest =
			RECT(tr->position_.getX(), tr->position_.getY(), tr->width_, tr->height_);
		img->tex_->render(dest, tr->rotation_, clip);

	}
	void drawScore() {
		auto sc =
				mngr_->getHandler<_hdlr_GameState>()->getComponent<Score>();
		Texture scoreMsg(game_->getRenderer(),"Score :"+ std::to_string(sc->points_),
				game_->getFontMngr()->getFont(Resources::ARIAL24),
				{ COLOR(0x0000ffff) });
		scoreMsg.render(game_->getWindowWidth() / 2 - scoreMsg.getWidth() / 2,
				10);

	}
	void drawLifes() {
		int x = 15;
		 mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_ ;
		for (int i = 0; i < mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_; i++) {
			vidaTex->render(x, 10);
			x += 30;
		}
	}
private:
Texture*	vidaTex;
};

