#pragma once

class CGame
{
public:
	bool Gamestarted = false;
	void GameInit();
	void GameUpdate(double _elapsed);
	void GameEnd();
	void LoadMainMenu();
};


