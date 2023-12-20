#include "PlayerComponent.h"
#include "AddPositionMsg.h"
#include "CGame.h"
#include "NewPosMsg.h"
#include "MovementComponent.h"
#include "entity.h"
#include "EntityManager.h"

PlayerComponent::PlayerComponent(Entity* _owner, int _lives)
{
  Owner = _owner;
  Shot = EntityManager::getInstance()->CreateShotEntity(vec2(-100, -100));
}

void PlayerComponent::Update(float _elapsedTime)
{
  AddPositionMsg msg;
  
  if ((GetKeyState('A') & 0x8000))
  {
    ResetInput = true;
    msg.addValue = vec2(-10.f , 0);
    Owner->SendMsg(&msg);
  }
  else if ((GetKeyState('D') & 0x8000))
  {
    ResetInput = true;
    msg.addValue = vec2(10, 0);
    Owner->SendMsg(&msg);
  }
  else if ((GetKeyState('S') & 0x8000) && !Shot->Enabled)
  {
    Shot->FindComponent<MovementComponent>()->set_pos(Pos + vec2(0, 30));
    Shot->Enable();
  }
}

void PlayerComponent::RecieveMessage(Message* message)
{
  NewPosMsg* posmsg = dynamic_cast<NewPosMsg*>(message);
  if (posmsg)
  {
    Pos = posmsg->Pos;
  }
}

void PlayerComponent::removeLife()
{
  CGame* game =  CGame::getInstance();
  game->set_lives(game->get_lives()-1);
  
  if (game->get_lives() >= 0)
  {
    game->SetCanRestart(true);
    //CGame::getInstance()->LoadLevel(CGame::getInstance()->Currentlevel);
  } 
}
