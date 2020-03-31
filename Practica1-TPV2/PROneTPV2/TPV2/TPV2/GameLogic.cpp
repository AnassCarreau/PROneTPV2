#include "GameLogic.h"
#include "Collisions.h"
#include "Resources.h"
#include "Entity.h"

GameLogic::GameLogic(Transform* fighter, AsteroidPool* ast, BulletsPool* bala, Health* vida) :
	Component(ecs::GameLogic), //
	fighter_(fighter), //
	ast_(ast),
	bala_(bala),
	vida_(vida),
	scoreManager_(nullptr) //
{
}



void GameLogic::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
	
}

void GameLogic::update() {
	if (!scoreManager_->getPause() && fighter_ != nullptr)
	{

		for (auto& o : ast_->getPool())
		{
			if (o->isInUse())
			{


				if (Collisions::collidesWithRotation
				(fighter_->getPos(), fighter_->getW(), fighter_->getH(), fighter_->getRot(),
					o->getPos(), o->getW(), o->getH(), o->getRot()))
				{
					ast_->disablAll();
					bala_->disablAll();
					cout << "dado";
					if (!vida_->RestaVida())
					{
						scoreManager_->isWin(false);
						scoreManager_->setPlay(false);
						game_->getAudioMngr()->resumeMusic();

					}
					
					scoreManager_->setPause(true);
					game_->getAudioMngr()->haltMusic();
					fighter_->setPos(Vector2D(game_->getWindowWidth() / 2,
					game_->getWindowHeight() / 2));
					fighter_->setVel(Vector2D(0.0, 0.0));
					fighter_->setRot(0);
				}

				for (auto& a : bala_->getPool())
				{
					if (a->isInUse())
					{
						if (Collisions::collidesWithRotation
						(a->getPos(), a->getW(), a->getH(), a->getRot(),
							o->getPos(), o->getW(), o->getH(), o->getRot()))
						{
							ast_->onCollision(o, a);
							bala_->onCollision(a,o);
							scoreManager_->setScore(scoreManager_->getScore() + 1);
							if (ast_->getNumOfAsteroid() == 0)
							{
								scoreManager_->isWin(true);
								scoreManager_->setPlay(false);
								scoreManager_->setPause(true);

								fighter_->setPos(Vector2D(game_->getWindowWidth() / 2,
									game_->getWindowHeight() / 2));
								fighter_->setVel(Vector2D(0.0, 0.0));
								fighter_->setRot(0);

							}
						}
					}

				}
			}
		}
	}
}


