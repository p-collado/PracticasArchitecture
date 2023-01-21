#pragma once
//#include "ball.h"
#include<vector>

class ball;
class EntityManager
{

  EntityManager();
  static EntityManager* instance;
  const int NUM_BALL = 10;
  std::vector<class ball*> balls;
  float MAX_BALL_SPEED = 8.f * 60;
  

public:
  inline static EntityManager* getInstance() {
    if (instance)
    {
      return instance;
    }
    else
    {
      instance = new EntityManager();
    }
  }

  inline int getNumBalls() { return NUM_BALL; };                  
  inline std::vector<class ball*> getBalls() { return balls; };         
  inline float getSpeed() { return MAX_BALL_SPEED; };             
  void Init();                                                    
                                                                  
                                                                  
};                                                                
                                                                  
                                                                  