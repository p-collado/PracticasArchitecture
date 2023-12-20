#include "BallComponent.h"
#include "HookComponent.h"
#include "PlayerComponent.h"
#include "CollisionComponent.h"
#include "entity.h"
#include "MultVelocityMsg.h"
#include "AddVelocityMsg.h"
#include "CGame.h"
#include "EntCollisionMsg.h"
#include "EntityManager.h"
#include "LimitWorldCallMsg.h"
#include "NewPosMsg.h"

BallComponent::BallComponent(Entity* _Eowner, int _splits)
{
  Owner = _Eowner;
  gravity = vec2(0, -9.8);
  splits = _splits;
}

BallComponent::~BallComponent()
{
}

void BallComponent::Update(float _elapsedTime)
{
  AddVelocityMsg msg;
  msg.addValue = gravity;
  Owner->SendMsg(&msg);
}

void BallComponent::RecieveMessage(Message* message)
{
  LimitWorldCallMsg* limitCollMsg = dynamic_cast<LimitWorldCallMsg*>(message);
  if (limitCollMsg)
  {

    if (!limitCollMsg->Axis)
    {
      MultVelocityMsg msg;
      msg.multValue = vec2(-1, 1);
      Owner->SendMsg(&msg);
    }
    else
    {
      MultVelocityMsg msg1;
      msg1.multValue = vec2(1, 0);
      Owner->SendMsg(&msg1);

      AddVelocityMsg msg2;
      msg2.addValue = vec2(0, 500);
      Owner->SendMsg(&msg2);
    }
  }
  
  EntCollisionMsg* entCollMsg = dynamic_cast<EntCollisionMsg*>(message);
  if (entCollMsg)
  {
    HookComponent* hookComp = entCollMsg->otherEnt->FindComponent<HookComponent>();
    if (hookComp)
    {
      hookComp->disableShot();
      Owner->Disable();
      EntityManager::getInstance()->RemoveBall();
      --splits;
      EntityManager::getInstance()->SplitBalls(pos, Owner->FindComponent<CollisionComponent>()->get_radius()/2, splits);
    }

    PlayerComponent* playerComp = entCollMsg->otherEnt->FindComponent<PlayerComponent>();
    if (entCollMsg->otherEnt->FindComponent<PlayerComponent>())
    {
      Owner->Disable();
      CGame* game = CGame::getInstance();
      playerComp->removeLife();
    }
  }

  NewPosMsg* posmsg = dynamic_cast<NewPosMsg*>(message);
  if (posmsg)
  {
    pos = posmsg->Pos;
  }
}

