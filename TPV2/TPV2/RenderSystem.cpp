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

void RenderSystem::recieve(const msg::Message& msg)
{
	if (msg.id== msg::_PLAYER_NAME_MSG && msg.senderClientId != mngr_->getClientId())
	{
		if (mngr_->getClientId()==0)
		{
			strcpy_s(nameIzq,mngr_->getName());
			strcpy_s(nameDer, static_cast<const msg::PlayerNameMsg&>(msg).nombre);
			posBlanco = strlen(mngr_->getName())/13;
			//cout << strlen(mngr_->getName());
		}
		else
		{
			strcpy_s(nameIzq, static_cast<const msg::PlayerNameMsg&>(msg).nombre);
			strcpy_s(nameDer, mngr_->getName());
			posBlanco = game_->getWindowWidth() - 13* strlen( mngr_->getName());
			//cout << strlen(mngr_->getName());

		}
	}
	
}

void RenderSystem::update() {
	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Fighters)) {
		drawImage(e); // auto cast from unique_ptr to Entity*
	}

	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Bullets))
		drawImage(e); // auto cast from unique_ptr to Entity*

	drawCtrlMessages();
	drawScore();
	drawNames();
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

void RenderSystem::drawNames()
{
	game_->getTextureMngr()->getTexture(Resources::WhiteRect)->render(SDL_Rect{posBlanco ,10,(int)strlen( mngr_->getName())*13,24 });

	if (mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->getState()!=GameCtrlSystem::WAITING)
	{

		Texture name1(game_->getRenderer(), nameIzq,
			game_->getFontMngr()->getFont(Resources::ARIAL24),
			{ COLOR(0x111122ff) });
		name1.render(0, 10);

		Texture name2(game_->getRenderer(), nameDer,
			game_->getFontMngr()->getFont(Resources::ARIAL24),
			{ COLOR(0x111122ff) });
		name2.render(game_->getWindowWidth() - name2.getWidth(), 10);
	}
	else
	{

		Texture name1(game_->getRenderer(), mngr_->getName(),
			game_->getFontMngr()->getFont(Resources::ARIAL24),
			{ COLOR(0x111122ff) });
		name1.render(0, 10);

		

	}

	

}
