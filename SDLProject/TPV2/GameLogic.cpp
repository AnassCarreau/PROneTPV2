#include "GameLogic.h"
#include "Collisions.h"
#include "Resources.h"
#include "Entity.h"

GameLogic::GameLogic(Transform* hunterTR, AsteroidPool* asteroidPool, BulletsPool* bulletsPool, Heart* heart) : 
	hunterTR_(hunterTR), asteroidPool_(asteroidPool), bulletsPool_(bulletsPool), heart_(heart), Component(ecs::GameLogic){

}

GameLogic::~GameLogic() {
}

void GameLogic::init() {
	scoreManager_ = GETCMP1_(ScoreManager);
}

void GameLogic::update() {
	if (scoreManager_->isRunning()) {
		for (auto asteroid : asteroidPool_->getPool()) {
			if (asteroid->inUse()) {
				//Colisión con el caza
				if (Collisions::collidesWithRotation(hunterTR_->getPos(), hunterTR_->getW(), hunterTR_->getH(), hunterTR_->getRot(),
					asteroid->getPos(), asteroid->getW(), asteroid->getH(), asteroid->getRotation())) {
					bulletsPool_->disablAll();
					asteroidPool_->disablAll();
					heart_->loseHeart();
					hunterTR_->setPos(Vector2D(game_->getWindowWidth() / 2 - hunterTR_->getW() / 2, game_->getWindowHeight() / 2 - hunterTR_->getH() / 2));
					hunterTR_->setVel(Vector2D(0, 0));
					hunterTR_->setRot(0);

					scoreManager_->setRunning(false);

					if (heart_->getHearts() == 0) {
						scoreManager_->setFinishGame(true);
						scoreManager_->setWin(false);

						game_->getAudioMngr()->playMusic(Resources::Boooo, 0);
					}
					else game_->getAudioMngr()->playMusic(Resources::Missed, 0);
				}
				else {
					//Colisión con las balas
					for (auto bullet : bulletsPool_->getPool()) {
						if (bullet->inUse() && Collisions::collidesWithRotation(bullet->getPos(), bullet->getW(), bullet->getH(), bullet->getRotation(),
							asteroid->getPos(), asteroid->getW(), asteroid->getH(), asteroid->getRotation())) {
							bulletsPool_->onCollision(bullet);
							asteroidPool_->onCollision(asteroid);
							scoreManager_->addScore();

							if (asteroidPool_->getNumOfAsteroids() == 0) { //Cuando no quedan asteroides, se gana
								hunterTR_->setPos(Vector2D(game_->getWindowWidth() / 2 - hunterTR_->getW() / 2, game_->getWindowHeight() / 2 - hunterTR_->getH() / 2));
								hunterTR_->setVel(Vector2D(0, 0));
								hunterTR_->setRot(0);

								scoreManager_->setRunning(false);
								scoreManager_->setFinishGame(true);
								scoreManager_->setWin(true);

								game_->getAudioMngr()->playMusic(Resources::Cheer, 0);
							}
							else game_->getAudioMngr()->playChannel(Resources::Explosion, 0);
						}
					}
				}
			}
		}
	}

	// check for collision of ball with paddles
	//if (Collisions::collides(ballTR_->getPos(), ballTR_->getW(),
	//		ballTR_->getH(), leftPaddleTR_->getPos(), leftPaddleTR_->getW(),
	//		leftPaddleTR_->getH())
	//		|| Collisions::collides(ballTR_->getPos(), ballTR_->getW(),
	//				ballTR_->getH(), rightPaddleTR_->getPos(),
	//				rightPaddleTR_->getW(), rightPaddleTR_->getH())) {
	//	Vector2D v = ballTR_->getVel();
	//	v.setX(-v.getX());
	//	ballTR_->setVel(v * 1.2);
	//	game_->getAudioMngr()->playChannel(Resources::Paddle_Hit, 0);
	//}

	//// check if the back exit from sides
	//if (ballTR_->getPos().getX() <= 0) {
	//	scoreManager_->setRightScore(scoreManager_->getRightScore() + 1);
	//	scoreManager_->setRunning(false);
	//	ballTR_->setVel(Vector2D(0, 0));
	//	ballTR_->setPos(
	//			Vector2D(game_->getWindowWidth() / 2 - 6,
	//					game_->getWindowHeight() / 2 - 6));

	//} else if (ballTR_->getPos().getX() + ballTR_->getW()
	//		>= game_->getWindowWidth()) {
	//	scoreManager_->setLeftScore(scoreManager_->getLeftScore() + 1);
	//	scoreManager_->setRunning(false);
	//	ballTR_->setPos(
	//			Vector2D(game_->getWindowWidth() / 2 - 6,
	//					game_->getWindowHeight() / 2 - 6));
	//	ballTR_->setVel(Vector2D(0, 0));
	//}
}

