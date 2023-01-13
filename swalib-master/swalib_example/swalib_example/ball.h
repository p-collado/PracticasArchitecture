#pragma once
#include "../../common/vector2d.h"
#include "../../common/stdafx.h"
class ball
{
public:
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint gfx;	// OpenGL for id. for visualization purposes.
	float  radius;	// Radius.

	inline float getRadius() { return radius; };
	inline vec2 getPos() { return pos; };
	inline vec2 getVel() { return vel; };
	inline unsigned int getGFX() { return gfx; };
	void setRadius(float _radius);
	void setPos(vec2 _pos);
	void setVel(vec2 _vel);
	void setGFX(unsigned int _gfx);

	ball() :
		pos(0.0f),
		vel(0.0f),
		gfx(0),
		radius(0.0f)
	{}
};

