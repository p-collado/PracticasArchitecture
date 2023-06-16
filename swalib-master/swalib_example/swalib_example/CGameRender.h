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
  std::vector<char*> texts;
  static CGameRender* instance;
  bool gamestarted;
  float FPS;
  float tiempotranscurrido;
  float Tiempologica;

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

  void GetTiempos(float fps, float tt, float tl);
  void DrawMenu();
  void DrawTexts();
  void RenderInit();
  void Draw();
  void RenderEnd();
  void PushText(char* string);
  CTexture* LoadTexture(const char* filename, bool _alpha);
  CTexture* getTexture(const char* filename);
  SpriteComponent* getSpriteinPos(int i);
  void PushSprite(SpriteComponent& ref);
};

