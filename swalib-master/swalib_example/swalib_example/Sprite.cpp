#include "Sprite.h"
#include "../../common/core.h"

void Sprite::setTexture(unsigned int _texture)
{
  id = _texture;
}

void Sprite::LoadTexture(const char* filename, bool _alpha)
{
  id = CORE_LoadPNG(filename, true);
}
