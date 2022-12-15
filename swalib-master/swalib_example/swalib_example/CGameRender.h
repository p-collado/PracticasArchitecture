#pragma once

class CGameRender
{
public:
  unsigned int texbkg;
  unsigned int texsmallball;

  void RenderInit();
  void Draw();
  void RenderEnd();
};

