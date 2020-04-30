#pragma once
#include "SDL_macros.h"
#include "checkML.h"

class RenderSystem: public System {
public:
	RenderSystem() :vidaTex(nullptr), clip(SDL_Rect{0,0,0,0}) {}
	void init()override
	{
		vidaTex = game_->getTextureMngr()->getTexture(Resources::Heart);
		clip ={47,90,207,250};
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
			draw(mngr_->getHandler<_hdlr_Fighter>());
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
		if (e->getComponent<Health>()==nullptr)
		{
			img->tex_->render(dest, tr->rotation_);
		}
		else  img->tex_->render(dest, tr->rotation_, clip);
	}
	void drawScore() {
		auto sc =
				mngr_->getHandler<_hdlr_GameState>()->getComponent<Score>();
		Texture scoreMsg(game_->getRenderer(),"Score :"+ std::to_string(sc->points_),
				game_->getFontMngr()->getFont(Resources::FontId::ARIAL24),
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
Texture*vidaTex;
SDL_Rect clip;
};

