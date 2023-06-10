#pragma once
#include<vector>

class CBackground;
class SpriteComponent;
class Entity;
class EntityManager
{

  EntityManager();
  static EntityManager* instance;
  const int NUM_BALL = 10;
  std::vector<Entity*> balls;
  CBackground* back;

public:
  inline static EntityManager* getInstance() {
    if (instance)
    {
      return instance;
    }
    else
    {
     return instance = new EntityManager();
    }
  }
  void Slot(double _elapsed);
  inline int getNumBalls() { return NUM_BALL; }            
  inline std::vector< Entity*> getBalls() { return balls; }        
  // inline float getSpeed() { return MAX_BALL_SPEED; }          
  void Init();                                                    
};                                                                
                                                                  
                                                                  