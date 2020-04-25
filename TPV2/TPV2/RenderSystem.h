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
				cadena = "Press Any Key to start";
				break;
			case GameState::Pause:
				cadena = "Press Any Key to play";
				break;
			case GameState::FinishWin:
				cadena = "You win";

				break;
			case GameState::FinishLose:
				cadena = "You lose";

				break;

			}
			Texture msg(game_->getRenderer(), cadena, game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0xff0000ff) });
			msg.render(game_->getWindowWidth() / 2 - msg.getWidth() / 2, game_->getWindowHeight() - msg.getHeight() - 10);
		}

		/*else if (state->estado == state->Pause ||state->estado==state->Start)
		{
			
			Texture msg(game_->getRenderer(), "Press ENTER to add More Stars", game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0xff0000ff) });
			msg.render(game_->getWindowWidth() / 2 - msg.getWidth() / 2, game_->getWindowHeight() - msg.getHeight() - 10);
		}
		else
		{
			if (state->estado == state->FinishLose)
			{
				Texture msg(game_->getRenderer(), "YOU LOSE", game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0xff0000ff) });
				msg.render(game_->getWindowWidth() / 2 - msg.getWidth() / 2, game_->getWindowHeight() - msg.getHeight() - 10);
			}
			else
			{
				Texture msg(game_->getRenderer(), "YOU WIN", game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0xff0000ff) });
				msg.render(game_->getWindowWidth() / 2 - msg.getWidth() / 2, game_->getWindowHeight() - msg.getHeight() - 10);
			}
		}*/
		
		
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
		Texture scoreMsg(game_->getRenderer(), std::to_string(sc->points_),
				game_->getFontMngr()->getFont(Resources::ARIAL24),
				{ COLOR(0x0000ffff) });
		scoreMsg.render(game_->getWindowWidth() / 2 - scoreMsg.getWidth() / 2,
				10);

	}
	void drawLifes() {
		
		int x = 15;
		 mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_ ;

		for (int i = 0; i < mngr_->getHandler<_hdlr_Fighter>()->getComponent<Health>()->vidas_; i++) {
			game_->getTextureMngr()->getTexture(Resources::Heart)->render(x, 10);
			x += 30;
		}
	}
};

