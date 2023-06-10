#include "Entity.h"
#include "../../common/sys.h"
#include "../../common/core.h"
#include "EntityManager.h"
#include <vector>
#include "CollisionComponent.h"
#include "Componente.h"
#include "MovementComponent.h"


// void Entity::setRadius(float _radius)
// {
// 	radius = _radius;
// }
//
// void Entity::setPos(vec2 _pos)
// {
// 	pos = _pos;
// }
//
// void Entity::setVel(vec2 _vel)
// {
// 	vel = _vel;
// }

void Entity::Slot(double _elapsed)
{
	// // Run balls
	// vec2 newpos = pos + vel * _elapsed;
	//
	// renderinfo.setPos(newpos);
	
	for (auto element : vComponents)
	{
		element->Update(_elapsed);
	}
	
}

Entity::Entity(int _id) /*: renderinfo(filename, false)*/
{
	// float MAX_BALL_SPEED = EntityManager::getInstance()->getSpeed();
	id = _id;
	// pos = (vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)));
	// vel = (vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED)));
	// radius = 16.f;
	//renderinfo.setSize(vec2(radius * 2, radius * 2));
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
