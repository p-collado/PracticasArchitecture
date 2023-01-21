#include "EntityManager.h"
#include "ball.h"

EntityManager* EntityManager::instance= nullptr;

void EntityManager::Init()
{

	for (int i = 0; i < NUM_BALL; i++) {

		balls.push_back(new ball(i));
	}
}


EntityManager::EntityManager()
{
	
}
