#pragma once
#include<unordered_map>
#include<vector>

class CTexture;
class SpriteComponent;
class CGameRender
{
  CGameRender();
  std::unordered_map<const char*, CTexture*> maptexture;
  std::vector<SpriteComponent*> spritesref;
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
      return instance = new CGameRender();
    }
  }

  void RenderInit();
  void Draw();
  void RenderEnd();
  CTexture* LoadTexture(const char* filename, bool _alpha);
  CTexture* getTexture(const char* filename);
  SpriteComponent* getSpriteinPos(int i);
  void PushSprite(SpriteComponent& ref);
};

