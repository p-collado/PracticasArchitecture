#pragma once
class Sprite
{
  unsigned int id;
public:
  void setTexture(unsigned int _texture);
  inline unsigned int getTexture() { return id; };
  void LoadTexture(const char* filename, bool _alpha);

};

