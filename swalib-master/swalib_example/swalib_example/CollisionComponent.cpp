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

CollisionComponent::CollisionComponent(Entity* owner, float _Radius)
{
    Owner = owner;
    Radius = _Radius;
}

void CollisionComponent::Update(float elapsed)
{
    // Collision detection.
    // bool collision = false;
    // int colliding_ball = -1;
    // EntityManager* instance = EntityManager::getInstance();
    // for (int j = 0; j < EntityManager::getInstance()->getNumBalls(); j++) {
    //     if (Owner->getId() != j) {
    //         float radiusj = instance->getBalls()[j]->FindComponent<CollisionComponent>()->get_radius();
    //         float limit2 = (Radius + radiusj) * (Radius + radiusj);
    //         if (vlen2(Pos - instance->getBalls()[j]->FindComponent<MovementComponent>()->get_pos()) <= limit2) {
    //             collision = true;
    //             colliding_ball = j;
    //             break;
    //         }
    //     }
    // }
    // if (collision) {
    //
    //     EntCollisionMsg EntColMsg;
    //     Owner->SendMsg(&EntColMsg);
    // }
    
    // Rebound on margins.
    
    LimitWorldCallMsg LimitMsg;
    
    if ((Pos.x > SCR_WIDTH - Radius) || Pos.x < Radius)
    {
        //vec2 newvel = vec2(Vel.x * -1.f, Vel.y);
        LimitMsg.Axis = false;
        //LimitMsg.VelLimit = newvel;
        Owner->SendMsg(&LimitMsg);
    }
    
    if ((Pos.y > SCR_HEIGHT - Radius - 1) || (Pos.y < Radius + 101))
    {
        LimitMsg.Axis = true;
        //vec2 newvel = vec2(Vel.x, Vel.y * -1.f);
        //LimitMsg.VelLimit = newvel;
        Owner->SendMsg(&LimitMsg);
    }
}

void CollisionComponent::RecieveMessage(Message* Msg)
{
    NewPosMsg* PosMsg = dynamic_cast<NewPosMsg*>(Msg);
    
    if (PosMsg)
    {
        Pos = PosMsg->Pos;
        //Vel = PosMsg->Vel;
    }
}
