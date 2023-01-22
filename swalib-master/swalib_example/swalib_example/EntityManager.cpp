#include "EntityManager.h"
#include "ball.h"
#include "CGameRender.h"
#include<unordered_map>
#include "Sprite.h"
#include "CBackground.h"

EntityManager* EntityManager::instance= nullptr;

void EntityManager::Init()
{
	back = new CBackground;
	back->setSprite(CGameRender::getInstance()->getSpriteinPos(0));

	for (int i = 0; i < NUM_BALL; i++)
	{
		balls.push_back(new ball(i));
		balls[i]->setSprite(CGameRender::getInstance()->getSpriteinPos(i+1));
	}
}


void EntityManager::setSpriteComponent(std::vector<Sprite*> spriteref) const
{
	for (int i = 0; i < NUM_BALL; i++)
	{
		balls[i]->setSprite(spriteref[i]);
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
