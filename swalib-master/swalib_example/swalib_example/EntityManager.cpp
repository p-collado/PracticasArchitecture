#include "EntityManager.h"
#include "Entity.h"
#include "CGameRender.h"
#include<unordered_map>
#include "SpriteComponent.h"
#include "CBackground.h"
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "../../common/sys.h"

EntityManager* EntityManager::instance= nullptr;

void EntityManager::Init()
{
	back = new CBackground("data/circle-bkg-128.png", vec2(SCR_WIDTH, SCR_HEIGHT));
	CGameRender::getInstance()->PushSprite(*back);

	for (int i = 0; i < NUM_BALL; i++)
	{
		balls.push_back(new Entity(i));
		balls[i]->AddComponent(new CollisionComponent(balls[i], 20));
		balls[i]->AddComponent(new MovementComponent(balls[i]));
		balls[i]->AddComponent(new SpriteComponent(balls[i], vec2(20, 20), "data/tyrian_ball.png", false));
		CGameRender::getInstance()->PushSprite(*(balls[i]->FindComponent<SpriteComponent>()));
	}
}


void EntityManager::Slot(double _elapsed)
{
	for (int i = 0; i < NUM_BALL; i++) {

		balls[i]->Slot(_elapsed);

	}
}

EntityManager::EntityManager()
{

}
