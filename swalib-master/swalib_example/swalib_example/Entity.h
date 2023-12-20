#pragma once
#include "SpriteComponent.h"

class Componente;
class Entity
{
	int id;

public:
	static int counter;
	bool Enabled = true;
	const int getId(){return id;}
	void Slot(double _elapsed);
	Entity(int id);
	Entity();
	std::vector<Componente*> vComponents;
	void AddComponent(Componente* comp);
	void SendMsg(Message* Msg) const;
	void Disable();
	void Enable();

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

