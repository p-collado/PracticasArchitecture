#pragma once
//#include "../../common/vector2d.h"
//#include "../../common/stdafx.h"
#include "SpriteComponent.h"

class Componente;
class Entity
{
	static int counter;
	int id;
	// vec2   pos;	// Position.
	// vec2   vel;	// Velocity.
	// //GLuint gfx;	// OpenGL for id. for visualization purposes.
	// //SpriteComponent renderinfo;
	// float  radius;	// Radius.

public:
	const int getId(){return id;}
	// inline float getRadius() { return radius; }
	// inline vec2 getPos() { return pos; }
	// inline vec2 getVel() { return vel; }
	// void setRadius(float _radius);
	// void setPos(vec2 _pos);
	// void setVel(vec2 _vel);
	void Slot(double _elapsed);
	Entity(int id);
	std::vector<Componente*> vComponents;
	void AddComponent(Componente* comp);
	void SendMsg(Message* Msg) const;

	template<typename T>
	T* FindComponent()
	{
		for (auto element : vComponents)
		{
			T* comp = dynamic_cast<T*>(element);
			if(comp)
			{
				return comp;
			}
		}
		return nullptr;
	}
};

