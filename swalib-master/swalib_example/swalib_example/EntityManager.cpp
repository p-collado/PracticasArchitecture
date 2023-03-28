#include "EntityManager.h"
#include "Entity.h"
#include "CGameRender.h"
#include<unordered_map>
#include "Sprite.h"
#include "CBackground.h"
#include "../../common/sys.h"

EntityManager* EntityManager::instance= nullptr;

void EntityManager::Init()
{


	back = new CBackground("data/circle-bkg-128.png", vec2(SCR_WIDTH, SCR_HEIGHT));
	CGameRender::getInstance()->PushSprite(*back);

	for (int i = 0; i < NUM_BALL; i++)
	{
		balls.push_back(new Entity(i, "data/tyrian_ball.png"));
		CGameRender::getInstance()->PushSprite(*(balls[i]->FindComponent<Sprite>()));
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
