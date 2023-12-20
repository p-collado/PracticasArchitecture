#include "Entity.h"
#include <vector>
#include "Componente.h"


int Entity::counter;

void Entity::Slot(double _elapsed)
{
	for (auto element : vComponents)
	{
		element->Update(_elapsed);
	}
}

Entity::Entity(int _id)
{
	id = _id;
}

Entity::Entity()
{
	
}

void Entity::AddComponent(Componente* comp)
{
	vComponents.push_back(comp);
}

void Entity::SendMsg(Message* Msg) const
{
	for (auto& vComponent : vComponents)
	{
		vComponent->RecieveMessage(Msg);
	}
}

void Entity::Disable()
{
	Enabled = false;
	SpriteComponent* temp = FindComponent<SpriteComponent>();
	if (temp)
	{
		temp->Disable();
	}
}

void Entity::Enable()
{
	Enabled = true;
	SpriteComponent* temp = FindComponent<SpriteComponent>();
	if (temp)
	{
		temp->Enable();
	}
}