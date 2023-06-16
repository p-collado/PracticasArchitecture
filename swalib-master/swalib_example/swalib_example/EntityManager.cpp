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
	
	for (int i = 0; i < NUM_BALL; i++)
	{
		Entities.push_back(new Entity(i));
		Entities[i]->AddComponent(new MovementComponent(Entities[i]));
		Entities[i]->AddComponent(new CollisionComponent(Entities[i], 20));
		Entities[i]->AddComponent(new SpriteComponent(Entities[i], vec2(20, 20), "data/tyrian_ball.png", false));
		++EntityCounter;
	}

	Player = new Entity(EntityCounter);
	Entities.push_back(Player);
	++EntityCounter;
}


void EntityManager::Slot(double _elapsed)
{
	for (int i = 0; i < NUM_BALL; i++) {

		Entities[i]->Slot(_elapsed);
	}
	SYS_Pump();	// Process Windows messages.
}

EntityManager::EntityManager()
{

}
