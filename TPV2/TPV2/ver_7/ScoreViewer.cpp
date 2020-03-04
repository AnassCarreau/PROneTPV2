#include "ScoreViewer.h"

#include "Texture.h"
#include "Entity.h"
#include "SDL_macros.h"

ScoreViewer::ScoreViewer() :
	Component(ecs::ScoreViewer), //
	scoreManager_(nullptr) {
}

ScoreViewer::~ScoreViewer() {
}

void ScoreViewer::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}

void ScoreViewer::draw() {

	Texture score(game_->getRenderer(),
		to_string(scoreManager_->getScore()),
		game_->getFontMngr()->getFont(Resources::ARIAL24),
		{ COLOR(0x111122ff) });
	score.render(
		game_->getWindowWidth() / 2 - score.getWidth() / 2, 10);
	if (!scoreManager_->getPlay()   )
	{
		string texto;
		if (!scoreManager_->getGameOver())
		{
			texto = "Game Over! You won!";
		}
		else
		{
			texto = "Game Over! You lost!";

		}
		Texture score(game_->getRenderer(),
			texto,
			game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0x111122ff) });
		score.render(
			game_->getWindowWidth() / 2 - score.getWidth() / 2, 50);
	}
}
