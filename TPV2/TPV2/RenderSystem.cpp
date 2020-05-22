#include "RenderSystem.h"

#include "ecs.h"
#include "GameCtrlSystem.h"
#include "Manager.h"
#include "SDL_macros.h"
#include "SDLGame.h"

#include "Image.h"
#include "Transform.h"
#include "Texture.h"

RenderSystem::RenderSystem() :
		System(ecs::_sys_Render) {
}

void RenderSystem::update() {
	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Fighters)) {
		drawImage(e); // auto cast from unique_ptr to Entity*
	}

	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Bullets))
		drawImage(e); // auto cast from unique_ptr to Entity*

	drawCtrlMessages();
	drawScore();
}

void RenderSystem::drawImage(Entity *e) {
	Transform *tr = e->getComponent<Transform>(ecs::Transform);
	Texture *tex = e->getComponent<Image>(ecs::Image)->tex_;

	SDL_Rect dest =
	RECT(tr->position_.getX(), tr->position_.getY(), tr->width_,
			tr->height_);
	tex->render(dest, tr->rotation_);
}

void RenderSystem::drawCtrlMessages() {
	auto gameState =
		mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getState();

	if (gameState == GameCtrlSystem::WAITING) {
		Texture* waiting = game_->getTextureMngr()->getTexture(
			Resources::WaitingForPlayer);
		waiting->render(
			game_->getWindowWidth() / 2 - waiting->getWidth() / 2,
			game_->getWindowHeight() - waiting->getHeight() - 50);
	}
	else if (gameState != GameCtrlSystem::RUNNING) {
		auto msgTex = game_->getTextureMngr()->getTexture(
			Resources::PressEnter);
		msgTex->render((game_->getWindowWidth() - msgTex->getWidth()) / 2,
			(game_->getWindowHeight() - msgTex->getHeight() - 10));

	}

	if (gameState == GameCtrlSystem::GAMEOVER) {
		auto msgTex = game_->getTextureMngr()->getTexture(Resources::GameOver);
		auto game = mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl);
		Texture* winlose;
		msgTex->render((game_->getWindowWidth() - msgTex->getWidth()) / 2,
			(game_->getWindowHeight() - msgTex->getHeight()) / 2);
		if (game->getScore(mngr_->getClientId()) == 3)
		{
			winlose=game_->getTextureMngr()->getTexture(Resources::YouWin);
		}
		else
		{
			winlose = game_->getTextureMngr()->getTexture(Resources::YouLose);
		}
		winlose->render((game_->getWindowWidth() - winlose->getWidth()) / 2,
			100+(game_->getWindowHeight() - winlose->getHeight()) / 2);

	}

}

void RenderSystem::drawScore() {
	auto gameCtrl = mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl);

	Texture scoreTex(game_->getRenderer(),
			to_string(gameCtrl->getScore(0)) + " - "
					+ to_string(gameCtrl->getScore(1)),
			game_->getFontMngr()->getFont(Resources::ARIAL24),
			{ COLOR(0x111122ff) });
	scoreTex.render(game_->getWindowWidth() / 2 - scoreTex.getWidth() / 2, 10);
}
