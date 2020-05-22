#include "CollisionSystem.h"

#include "Collisions.h"
#include "BulletsSystem.h"
#include "FighterInfo.h"
#include "GameCtrlSystem.h"
#include "Transform.h"
#include "Manager.h"

CollisionSystem::CollisionSystem() :
		System(ecs::_sys_Collision) {
}

CollisionSystem::~CollisionSystem() {
}


void CollisionSystem::update() {
	auto gameCtrlSys = mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl);

	if (gameCtrlSys->getState() != GameCtrlSystem::RUNNING  || mngr_->getClientId() == 1)
		return;


	bool roundOver = false;

	//Micodigo
	auto f0 = mngr_->getHandler(ecs::_hdlr_Fighter0)->getComponent<Transform>(ecs::Transform);
	auto f1 = mngr_->getHandler(ecs::_hdlr_Fighter1)->getComponent<Transform>(ecs::Transform);

	if (Collisions::collidesWithRotation(f0->position_, f0->width_,
		f0->height_, f0->rotation_, f1->position_, f1->width_,
		f1->height_, f1->rotation_)) {

		roundOver = true;
		mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->onFightersDeath();
		mngr_->send<msg::OnFightersDeathMsg>();

	}


	//
	for (auto &f : mngr_->getGroupEntities(ecs::_grp_Fighters)) {
		auto fTR = f->getComponent<Transform>(ecs::Transform);

		for (auto &b : mngr_->getGroupEntities(ecs::_grp_Bullets)) {
			if (!b->isActive())
				continue;

			auto bTR = b->getComponent<Transform>(ecs::Transform);

			if (Collisions::collidesWithRotation(bTR->position_, bTR->width_,
					bTR->height_, bTR->rotation_, fTR->position_, fTR->width_,
					fTR->height_, fTR->rotation_)) {

				roundOver = true;
				auto id = f->getComponent<FighterInfo>(ecs::FighterInfo)->fighterId;
				//mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->onFighterDeath(id);
				mngr_->send<msg::OnFighterDeathMsg>(id);
			}
			
		}
		
	}
	

	if ( roundOver )
		mngr_->getSystem<BulletsSystem>(ecs::_sys_Bullets)->disableAll();
}

