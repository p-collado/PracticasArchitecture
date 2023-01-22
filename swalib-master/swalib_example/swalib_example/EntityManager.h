#pragma once
#include<vector>

class CBackground;
class Sprite;
class ball;
class EntityManager
{

  EntityManager();
  static EntityManager* instance;
  const int NUM_BALL = 10;
  std::vector< ball*> balls;
  CBackground* back;
  
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

  void setSpriteComponent(std::vector<Sprite*> spriteref) const;
  void Slot(double _elapsed);
  inline int getNumBalls() { return NUM_BALL; }            
  inline std::vector< ball*> getBalls() { return balls; }        
  inline float getSpeed() { return MAX_BALL_SPEED; }          
  void Init();                                                    
                                                                  
                                                                  
};                                                                
                                                                  
                                                                  