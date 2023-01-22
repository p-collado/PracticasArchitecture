#include "Sprite.h"

#include <cstdio>

#include "CTexture.h"

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
