#include "SpriteComponent.h"
#include "CGameRender.h"
#include "CTexture.h"
#include "Entity.h"
#include "..\..\common\core.h"
#include "MovementComponent.h"
#include "NewPosMsg.h"

SpriteComponent::SpriteComponent(Entity* Owner, vec2 Size, const char* texturepath, bool alpha)
{
  owner = Owner;
  texture = CGameRender::getInstance()->LoadTexture(texturepath, alpha);
  size = Size;
}


void SpriteComponent::setSize(vec2& _size)
{
  size = _size;
}

void SpriteComponent::setPos(vec2& _pos)
{
  pos = _pos;
}

CTexture* SpriteComponent::getTexture()
{
  return texture;
}

void SpriteComponent::setTexture(CTexture* _ref)
{
  texture = _ref;
}

void SpriteComponent::LoadTexture(const char* filename, bool _alpha)
{
  texture->LoadTexture(filename,_alpha);
}

void SpriteComponent::draw()
{
  CORE_RenderCenteredSprite(pos, size*2, this->getTexture()->getTextureId());
}

void SpriteComponent::free()
{
  
  CORE_UnloadPNG(texture->getTextureId());
  delete texture;
}

void SpriteComponent::Update(float elapsed)
{
  
}

void SpriteComponent::RecieveMessage(Message* Msg)
{
  NewPosMsg* PosMsg = dynamic_cast<NewPosMsg*>(Msg);
    
  if (PosMsg)
  {
    pos = PosMsg->Pos;
  }
}
