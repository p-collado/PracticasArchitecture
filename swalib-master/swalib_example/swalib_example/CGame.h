#pragma once

class CWorld;
class CGame
{
	CWorld* World;
public:
	void GameInit();
	void GameUpdate(double _elapsed);
	void GameEnd();
};


