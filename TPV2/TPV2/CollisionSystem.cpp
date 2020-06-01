#include "CollisionSystem.h"

#include "Collisions.h"
#include "FoodSystem.h"
#include "GameState.h"
#include "GhostsSystem.h"
#include "Manager.h"
#include "Transform.h"

CollisionSystem::CollisionSystem() :
		System(ecs::_sys_Collisions) {
}

void CollisionSystem::update() {

	auto gameState = mngr_->getHandler(ecs::_hdlr_GameStateEntity)->getComponent<GameState>(ecs::GameState);
	if ( gameState->state_ != GameState::RUNNING)
		return;

	auto ptr = mngr_->getHandler(ecs::_hdlr_PacManEntity)->getComponent<Transform>(ecs::Transform);

	// collision with food
	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Food)) {
		auto etr = e->getComponent<Transform>(ecs::Transform);
		if (Collisions::collides(ptr->position_, ptr->width_, ptr->height_,
				etr->position_, etr->width_, etr->height_)) {
			//Antes mngr_->getSystem<FoodSystem>(ecs::_sys_Food)->onEat(e);
			//Ahora mandamos la entidad junto con el mensaje de que se ha comido la cereza
			mngr_->send<msg::OnEatCherry>(e);
			
		}
	}

	// collision with ghosts
	for (auto &e : mngr_->getGroupEntities(ecs::_grp_Ghost)) {
		auto etr = e->getComponent<Transform>(ecs::Transform);
		if (Collisions::collides(ptr->position_, ptr->width_, ptr->height_,
				etr->position_, etr->width_, etr->height_)) {
			//Antes mngr_->getSystem<GhostsSystem>(ecs::_sys_Ghosts)->onCollisionWithPacMan(e);
			//Ahora mandamos el mensaje de que se ha producido la colision de pacman y un fantasma
			mngr_->send<msg::Message>(msg::_COLLISION);
				break;
		}
	}

}

