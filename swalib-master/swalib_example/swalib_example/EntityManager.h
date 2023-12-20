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
  int NUM_BALL;
  std::vector<Entity*> Entities;
  CBackground* back;
  Entity* Player;

public:
  static EntityManager* getInstance() {
    if (instance)
    {
      return instance;
    }
    return instance = new EntityManager();
  }
  void Slot(double _elapsed);
  void SplitBalls(vec2 pos, float radius, int splits);
  void RemoveBall();
  int GetCounterEntity();
  std::vector<Entity*>& GetEntities(){return Entities;}
  Entity* CreateShotEntity(vec2 _Pos);
  int getNumBalls() { return NUM_BALL; }            
  void Init();
  void LoadLevel1();
  void LoadLevel2();
  void Clear();
};