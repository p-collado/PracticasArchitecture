#include "EntityManager.h"
#include "Entity.h"
#include "CGameRender.h"
#include<unordered_map>
#include "BallComponent.h"
#include "SpriteComponent.h"
#include "CBackground.h"
#include "CollisionComponent.h"
#include "HookComponent.h"
#include "MovementComponent.h"
#include "PlayerComponent.h"
#include "../../common/sys.h"

EntityManager* EntityManager::instance= nullptr;

void EntityManager::Init()
{
	
}

void EntityManager::LoadLevel1()
{
	Clear();
	
	NUM_BALL = 2;
	back = new CBackground("data/circle-bkg-128.png", vec2(SCR_WIDTH, SCR_HEIGHT));
	
	for (int i = 0; i < NUM_BALL; ++i)
	{
		Entities.push_back(new Entity(i));
		Entities[i]->AddComponent(new MovementComponent(Entities[i], vec2(100 + (i * 100) ,400), vec2(25,0)));
		Entities[i]->AddComponent(new CollisionComponent(Entities[i], 20));
		Entities[i]->AddComponent(new BallComponent(Entities[i],2));
		Entities[i]->AddComponent(new SpriteComponent(Entities[i], vec2(20, 20), "data/tyrian_ball.png", false));
		++EntityCounter;
		Entity::counter++;
	}
	
	Player = new Entity(EntityCounter);
	Player->AddComponent(new MovementComponent(Player, vec2(300, 140.f), vec2(0,0)));
	Player->AddComponent(new CollisionComponent(Player, 30));
	Player->AddComponent(new PlayerComponent(Player, 3));
	Player->AddComponent(new SpriteComponent(Player, vec2(30, 30), "data/nave.png", false));
	Entities.push_back(Player);
	++EntityCounter;
}

void EntityManager::LoadLevel2()
{
	Clear();
	NUM_BALL = 1;
	back = new CBackground("data/spacebg.png", vec2(SCR_WIDTH, SCR_HEIGHT));
	
	for (int i = 0; i < NUM_BALL; ++i)
	{
		Entities.push_back(new Entity(i));
		Entities[i]->AddComponent(new MovementComponent(Entities[i], vec2(200 ,400), vec2(25,0)));
		Entities[i]->AddComponent(new CollisionComponent(Entities[i], 40));
		Entities[i]->AddComponent(new BallComponent(Entities[i],3));
		Entities[i]->AddComponent(new SpriteComponent(Entities[i], vec2(40, 40), "data/tyrian_ball.png", false));
		++EntityCounter;
		Entity::counter++;
	}

	Player = new Entity(EntityCounter);
	Player->AddComponent(new MovementComponent(Player, vec2(300, 140.f), vec2(0,0)));
	Player->AddComponent(new CollisionComponent(Player, 30));
	Player->AddComponent(new PlayerComponent(Player, 3));
	Player->AddComponent(new SpriteComponent(Player, vec2(30, 30), "data/nave.png", false));
	Entities.push_back(Player);
	++EntityCounter;
}

void EntityManager::Clear()
{
	for (int i = 0; i < Entities.size(); ++i)
	{
		delete Entities[i];
	}

	Entities.clear();
	Entity::counter = 0;
}

void EntityManager::Slot(double _elapsed)
{
	for (int i = 0; i < Entities.size(); ++i)
	{
		if (Entities[i]->Enabled)
		{
			Entities[i]->Slot(_elapsed);
		}
	}
	SYS_Pump();	// Process Windows messages.
}

void EntityManager::SplitBalls(vec2 pos, float radius, int splits)
{
	if (splits >= 0)
	{
		Entity* ball1 = new Entity(EntityCounter);
		ball1->AddComponent(new MovementComponent(ball1, pos, vec2(-50, 200)));
		ball1->AddComponent(new CollisionComponent(ball1, radius));
		ball1->AddComponent(new BallComponent(ball1, splits));
		ball1->AddComponent(new SpriteComponent(ball1, vec2(radius, radius), "data/tyrian_ball.png", false));
		ball1->Enabled = true;
		EntityCounter++;
		Entity::counter++;
		
		Entity* ball2 = new Entity(EntityCounter);
		ball2->AddComponent(new MovementComponent(ball2, pos, vec2(50, 200)));
		ball2->AddComponent(new CollisionComponent(ball2, radius));
		ball2->AddComponent(new BallComponent(ball2, splits));
		ball2->AddComponent(new SpriteComponent(ball2, vec2(radius, radius), "data/tyrian_ball.png", false));
		ball2->Enabled = true;
		Entity::counter++;
		EntityCounter++;
		Entities.push_back(ball1);
		Entities.push_back(ball2);
	}
}

void EntityManager::RemoveBall()
{
	--Entity::counter;
}

int EntityManager::GetCounterEntity()
{
	return Entity::counter;
}

Entity* EntityManager::CreateShotEntity(vec2 _Pos)
{
	Entity* shot = new Entity(EntityCounter);
	shot->AddComponent(new MovementComponent(shot, _Pos, vec2(0, 300)));
	shot->AddComponent(new CollisionComponent(shot, 8));
	shot->AddComponent(new HookComponent(shot));
	shot->AddComponent(new SpriteComponent(shot,vec2(16, 5) ,"data/shot.png", false));
	shot->Enabled = false;
	Entities.push_back(shot);
	++EntityCounter;
	return shot;
}

EntityManager::EntityManager()
{

}
