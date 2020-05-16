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

void CollisionSystem::recieve(const msg::Message& msg)
{
	switch (msg.id) {
	case msg::_AIRPLANE_INFO: {
		if (msg.senderClientId == mngr_->getClientId())
			return;

		Transform* FighterTR = nullptr;
		if (msg.senderClientId == 0) {
			FighterTR = mngr_->getHandler(ecs::_hdlr_Fighter0)->getComponent<
				Transform>(ecs::Transform);
		}
		else {
			FighterTR = mngr_->getHandler(ecs::_hdlr_Fighter1)->getComponent<
				Transform>(ecs::Transform);
		}

		FighterTR->position_.setY(static_cast<const msg::AirplaneInfoMsg&>(msg).y);

		break;
	}
	case msg::_START_ROUND: {
		const msg::StartRoundMsg& m = static_cast<const msg::StartRoundMsg&>(msg);
		/*auto ballTR = mngr_->getHandler(ecs::_hdlr_Ball)->getComponent<Transform>(
			ecs::Transform);
		ballTR->velocity_.set(m.x, m.y);*/
		break;
	}
	default:
		break;
	}
}

void CollisionSystem::update() {
	auto gameCtrlSys = mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl);

	if (gameCtrlSys->getState() != GameCtrlSystem::RUNNING)
		return;


	bool roundOver = false;

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
				mngr_->getSystem<GameCtrlSystem>(ecs::_sys_GameCtrl)->onFighterDeath(id);
			}
		}
	}

	if ( roundOver )
		mngr_->getSystem<BulletsSystem>(ecs::_sys_Bullets)->disableAll();
}

