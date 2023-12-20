#include "CollisionComponent.h"

#include "CollisionMsg.h"
#include "EntCollisionMsg.h"
#include "Entity.h"
#include "EntityManager.h"
#include "LimitWorldCallMsg.h"
#include "MovementComponent.h"
#include "NewPosMsg.h"
#include "../../common/sys.h"


// vec2 CollisionComponent::get_vel() const
// {
//     return Vel;
// }
//
// void CollisionComponent::set_vel(const vec2& vel)
// {
//     Vel = vel;
// }

vec2 CollisionComponent::get_pos() const
{
    return Pos;
}

void CollisionComponent::set_pos(const vec2& pos)
{
    Pos = pos;
}

float CollisionComponent::get_radius() const
{
    return Radius;
}

void CollisionComponent::set_radius(const float radius)
{
    Radius = radius;
}

CollisionComponent::CollisionComponent(Entity* owner, float radius)
{
    Owner = owner;
    Radius = radius;
}

void CollisionComponent::Update(float elapsed)
{
    EntityManager* myGame = EntityManager::getInstance();
    std::vector<Entity*> enitityList = myGame->GetEntities();
    const unsigned int numEnts = enitityList.size();

    for (unsigned int j = 0; j < numEnts; j++) {
        if(Owner->getId() != enitityList[j]->getId())
        {
            vec2 currentPos = enitityList[j]->FindComponent<MovementComponent>()->get_pos();
            float radiusj = enitityList[j]->FindComponent<CollisionComponent>()->get_radius();
            float limit2 = (Radius + radiusj) * (Radius + radiusj);
            if (vlen2(Pos - currentPos) <= limit2) {
                EntCollisionMsg collMsg;
                collMsg.otherEnt = enitityList[j];
                Owner->SendMsg(&collMsg);
                enitityList[j];
                break;
            }
        }
    }
    
    // Rebound on margins.
    
    LimitWorldCallMsg LimitMsg;
    
    if ((Pos.x > SCR_WIDTH - Radius) || Pos.x < Radius)
    {
        LimitMsg.Axis = false;
        Owner->SendMsg(&LimitMsg);
    }
    
    if ((Pos.y > SCR_HEIGHT - Radius - 1) || (Pos.y < Radius + 101))
    {
        LimitMsg.Axis = true;
        Owner->SendMsg(&LimitMsg);
    }
}

void CollisionComponent::RecieveMessage(Message* Msg)
{
    NewPosMsg* PosMsg = dynamic_cast<NewPosMsg*>(Msg);
    
    if (PosMsg)
    {
        Pos = PosMsg->Pos;
    }
}
