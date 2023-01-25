#pragma once
#include "Sprite.h"

class CBackground: public Sprite
{
    vec2 pos;
    vec2 size;

public:
    explicit CBackground(const char* filepath, vec2 size);
    const vec2 getPos() {return pos;}
    const vec2 getSize() {return size;}
    void setPos(const vec2& _pos) {pos = _pos;}
    void setSize(const vec2& _size) {size = _size;}
    virtual void draw() override;
};
