#pragma once
#include "../../common/vector2d.h"

class CTexture;
class Sprite
{
    CTexture* texture;
    vec2 pos;
    vec2 size;
  
public:
    Sprite();
    Sprite(const char* texturePath, bool alpha);
    void setSize(vec2& _size);
    inline vec2 getSize() const {return size;}
    void setPos(vec2& pos);
    inline vec2 getPos() const {return pos;}
    CTexture* getTexture();
    void setTexture(CTexture* _ref);
    void LoadTexture(const char* filename, bool _alpha);
    virtual void draw();
    void free();

};

