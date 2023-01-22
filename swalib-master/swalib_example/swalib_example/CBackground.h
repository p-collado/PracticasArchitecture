#pragma once
#include "../../common/vector2d.h"

class Sprite;
class CBackground
{
    vec2 pos;
    vec2 size;
    const Sprite* sprite;
public:
    CBackground();
    const Sprite* getSprite() {return sprite;}
    const vec2 getPos() {return pos;}
    const vec2 getSize() {return size;}
    void setPos(const vec2& _pos) {pos = _pos;}
    void setSize(const vec2& _size) {size = _size;}
    void setSprite(const Sprite* ref) {sprite = ref;}
};
