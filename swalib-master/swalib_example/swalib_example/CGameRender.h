#pragma once
#include<unordered_map>
class Sprite;
class CGameRender
{
  CGameRender();
  std::unordered_map<const char*, Sprite*> maptexture;
  static CGameRender* instance;

public:

 /* unsigned int texbkg;
  unsigned int texsmallball;*/

  inline static CGameRender* getInstance() {
    if (instance)
    {
      return instance;
    }
    else
    {
      instance = new CGameRender();
    }
  }

  void RenderInit();
  static void Draw();
  void RenderEnd();
  unsigned int LoadTexture(const char* filename, bool _alpha);
};

