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
	// Cuando se acabe el juego mostrará los siguientes mensajes
	if (scoreManager_->isFinish()) {
		Texture* gameOver = game_->getTextureMngr()->getTexture(Resources::GameOver); //Mensaje GameOver!
		gameOver->render(game_->getWindowWidth() / 2 - gameOver->getWidth() / 2, (game_->getWindowHeight() / 4) - gameOver->getHeight());

		if (scoreManager_->isWin()) { //Se gana
			Texture win(game_->getRenderer(), " You Won!", game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0x111122ff) });

			win.render(game_->getWindowWidth() / 2 - win.getWidth() / 2, (game_->getWindowHeight() / 4));
		}
		else { //Se pierde
			Texture lost(game_->getRenderer(), " You Lost!", game_->getFontMngr()->getFont(Resources::ARIAL24), { COLOR(0x111122ff) });

			lost.render(game_->getWindowWidth() / 2 - lost.getWidth() / 2, (game_->getWindowHeight() / 4));
		}
	}

	//Puntuación total del juego
	Texture score(game_->getRenderer(), "Score: " + to_string(scoreManager_->getScore()), game_->getFontMngr()->getFont(Resources::ARIAL24), 
		{ COLOR(0x111122ff) });

	score.render(game_->getWindowWidth() / 2 - score.getWidth() / 2, (game_->getWindowHeight() / 15) - score.getHeight() / 2);
}
