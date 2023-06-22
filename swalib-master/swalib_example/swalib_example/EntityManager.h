#pragma once
#include<vector>
#include "../../common/vector2d.h"

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

  void SplitBalls(vec2 pos, float radius, int splits);
  void RemoveBall();
  std::vector<Entity*>& GetEntities(){return Entities;}
 Entity* CreateShotEntity(vec2 _Pos);
  inline int getNumBalls() { return NUM_BALL; }            
  inline std::vector< Entity*> getBalls() { return Entities; }        
  // inline float getSpeed() { return MAX_BALL_SPEED; }          
  void Init();                                                    
};                                                                
                                                                  
                                                                  