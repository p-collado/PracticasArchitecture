#include "Sprite.h"
#include <cstdio>
#include "CGameRender.h"
#include "CTexture.h"
#include "..\..\common\stdafx.h"
#include "..\..\common\core.h"

Sprite::Sprite(Entity* Owner, const char* texturepath, bool alpha)
{
  owner = Owner;
  texture = CGameRender::getInstance()->LoadTexture(texturepath, alpha);
}


void Sprite::setSize(vec2& _size)
{
  size = _size;
}

void Sprite::setPos(vec2& _pos)
{
  pos = _pos;
}

CTexture* Sprite::getTexture()
{
  return texture;
}

void Sprite::setTexture(CTexture* _ref)
{
  texture = _ref;
}

void Sprite::LoadTexture(const char* filename, bool _alpha)
{
  texture->LoadTexture(filename,_alpha);
}

void Sprite::draw()
{
  CORE_RenderCenteredSprite(pos, size, this->getTexture()->getTextureId());
}

void Sprite::free()
{
  
  CORE_UnloadPNG(texture->getTextureId());
  delete texture;
}

void Sprite::Update(float elapsed)
{
    
}
