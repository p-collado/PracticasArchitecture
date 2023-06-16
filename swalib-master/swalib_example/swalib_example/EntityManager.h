#pragma once
#include<vector>

class CBackground;
class SpriteComponent;
class Entity;
class EntityManager
{

  int EntityCounter = 0;
  EntityManager();
  static EntityManager* instance;
  const int NUM_BALL = 10;
  std::vector<Entity*> Entities;
  CBackground* back;
  Entity* Player;

public:
  inline static EntityManager* getInstance() {
    if (instance)
    {
      return instance;
    }
     return instance = new EntityManager();
  }
  void Slot(double _elapsed);
  inline int getNumBalls() { return NUM_BALL; }            
  inline std::vector< Entity*> getBalls() { return Entities; }        
  // inline float getSpeed() { return MAX_BALL_SPEED; }          
  void Init();                                                    
};                                                                
                                                                  
                                                                  