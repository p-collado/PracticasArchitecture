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
  float FPS;
  float tiempotranscurrido;
  float Tiempologica;

public:

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
  void GetPlayerInfo(int& lives);
  void DrawMenu();
  void DrawTexts();
  void RenderInit();
  void Draw();
  void RenderEnd();
  void DrawGameOverMenu();
  void PushText(char* string);
  CTexture* LoadTexture(const char* filename, bool _alpha);
  CTexture* getTexture(const char* filename);
  SpriteComponent* getSpriteinPos(int i);
  void PushSprite(SpriteComponent& ref);
  void DrawWinMenu();
};

