#include "GameLogic.h"
#include "Collisions.h"
#include "Resources.h"
#include "Entity.h"

GameLogic::GameLogic(Transform* fighter, AsteroidPool* ast, BulletsPool* bala) :
		Component(ecs::GameLogic), //
		fighter_(fighter), //
		ast_(ast),
	bala_(bala),
		scoreManager_(nullptr) //
{
}

GameLogic::~GameLogic() {
}

void GameLogic::init() {
	// scoreManager_ = GETCMP2(ecs::ScoreManager,ScoreManager);
	scoreManager_ = GETCMP1_(ScoreManager);
	//bala_ = GETCMP1_(BulletsPool);
	//ast_ = GETCMP1_(AsteroidPool);
	//vida_ = GETCMP1_(Health);
}

void GameLogic::update() {
	if (!scoreManager_->getPausing())
	{
		for (auto& o : ast_->getPool())
		{
			if (Collisions::collidesWithRotation
			(fighter_->getPos(), fighter_->getW(), fighter_->getH(), fighter_->getRot(),
				o->getPos(), o->getW(), o->getH(), o->getRot()))
			{
				ast_->disablAll();
				bala_->disablAll();
				scoreManager_->setPausing(true);
				if (!vida_->RestaVida())
				{
					scoreManager_->isGameOver(false);
					fighter_->setPos(Vector2D(game_->getWindowWidth() / 2,
						game_->getWindowHeight() / 2));
					fighter_->setVel(Vector2D(0.0, 0.0));
					fighter_->setRot(0);

				}
			}

			for (auto& a : bala_->getPool())
			{
				/*if (a->isUse())
				{

1				}*/
				if (Collisions::collidesWithRotation
				(a->getPos(), a->getW(), a->getH(), a->getRot(),
					o->getPos(), o->getW(), o->getH(), o->getRot()))
				{
					ast_->onCollision(o,a);
					//bala_->onCollision(a,o);
					scoreManager_->setScore(scoreManager_->getScore() + 1);
					if (ast_->getNumOfAsteroid()==0)
					{
						scoreManager_->isGameOver(true);
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


