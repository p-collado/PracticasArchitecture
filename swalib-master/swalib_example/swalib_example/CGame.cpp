#include "CGame.h"
#include "CGameRender.h"
#include "../../common/font.h"
#include "../../common/core.h"
#include "../../common/sys.h"
#include "EntityManager.h"
#include<vector>

//tballs balls; 	// Array of balls.

void CGame::GameInit()
{
	float MAX_BALL_SPEED = EntityManager::getInstance()->getSpeed();
	int NUM_BALLS = EntityManager::getInstance()->getNumBalls();
	std::vector<ball*> ref = EntityManager::getInstance()->getBalls();
	//-----------------------------------------------------------------------------
// Logic Info.
	//const float MAX_BALL_SPEED = 8.f;	// Max vel. of ball. (pixels/?).

	// Init game state.
}

void CGame::GameUpdate(double _elapsed)
{
	int NUM_BALLS = EntityManager::getInstance()->getNumBalls();

	std::vector<ball*> ref = EntityManager::getInstance()->getBalls();

	// Run balls
	for (int i = 0; i < NUM_BALLS; i++) {

		ref[i]->Slot(_elapsed);

	}
}

void CGame::GameEnd()
{

}
