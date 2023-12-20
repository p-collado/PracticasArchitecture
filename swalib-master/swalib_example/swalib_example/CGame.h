#pragma once

class CGame
{
	static CGame* instance;
	CGame();
	bool Gamestarted;
	bool CanRestart;
	int Currentlevel;
	int Lives;//esto esta feo mejor hacer un PlayerPackcage o algo asi con la info pero no hay tiempo.
	
public:
	bool is_gamestarted() const;
	void set_gamestarted(bool gamestarted);
	bool is_can_restart() const;
	void set_can_restart(bool can_restart);
	int get_currentlevel() const;
	void set_currentlevel(int currentlevel);
	int get_lives() const;
	void set_lives(int lives);
	void InitValues();
	void LoadWinMenu();
	static CGame* getInstance();
	void SetCanRestart(bool value);
	void GameInit();
	void GameUpdate(double _elapsed);
	void GameEnd();
	void LoadMainMenu();
	void LoadLevel1();
	void LoadLevel2();
	void LoadLevel(int level);
	void LoadGameOverMenu();
};


