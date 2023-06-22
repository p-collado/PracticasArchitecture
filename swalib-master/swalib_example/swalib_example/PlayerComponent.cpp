#include "PlayerComponent.h"
#include "AddPositionMsg.h"
#include "NewPosMsg.h"
#include "MovementComponent.h"
#include "entity.h"
#include "EntityManager.h"

PlayerComponent::PlayerComponent(Entity* _Eowner, int _lives)
{
  Owner = _Eowner;
  Lives = _lives;
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
    Shot->Enabled = true;
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
  Lives--;
  // gameManager::instance()->reload();
  // if (lives < 0)
  // {
  //   //game over
  // } //TODO
}
