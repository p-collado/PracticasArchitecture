#include "CollisionComponent.h"

#include "CollisionMsg.h"
#include "EntCollisionMsg.h"
#include "Entity.h"
#include "EntityManager.h"
#include "LimitWorldCallMsg.h"
#include "MovementComponent.h"
#include "NewPosMsg.h"
#include "../../common/sys.h"


vec2 CollisionComponent::get_vel() const
{
    return Vel;
}

void CollisionComponent::set_vel(const vec2& vel)
{
    Vel = vel;
}

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

CollisionComponent::CollisionComponent(Entity* owner, float _Radius, vec2 _Pos, vec2 _Vel)
{
    Owner = owner;
    Pos = _Pos;
    Radius = _Radius;
    Vel = _Vel;
}

void CollisionComponent::Update(float elapsed)
{
    //Pos = Owner->FindComponent<MovementComponent>()->get_pos();
    //NewPosMsg PosMsg;
    //Owner->SendMsg(&PosMsg);
    //Pos = PosMsg.Pos;
    //Vel = PosMsg.Vel;
    //Vel = Owner->FindComponent<MovementComponent>()->get_vel();

    vec2 newpos = Pos + Vel * elapsed;
    
    // Collision detection.
    bool collision = false;
    int colliding_ball = -1;
    for (int j = 0; j < EntityManager::getInstance()->getNumBalls(); j++) {
        if (Owner->getId() != j) {
            float limit2 = (Radius + EntityManager::getInstance()->getBalls()[j]->FindComponent<CollisionComponent>()->get_radius() * (Radius + EntityManager::getInstance()->getBalls()[j]->FindComponent<CollisionComponent>()->get_radius()));
            if (vlen2(newpos - EntityManager::getInstance()->getBalls()[j]->FindComponent<MovementComponent>()->get_pos()) <= limit2) {
                collision = true;
                colliding_ball = j;
                break;
            }
        }
    }
    if (!collision) { //TODO: CAMBIAR ESTO MAS BONITO
        //Owner->setPos(newpos);
        //Owner->FindComponent<MovementComponent>()->set_pos(newpos);
    }
    else {
        // Rebound!
        //Owner->setVel(Owner->getVel()*-1);
        EntCollisionMsg EntColMsg;
        Owner->SendMsg(&EntColMsg);
        //Owner->FindComponent<MovementComponent>()->set_vel(Owner->FindComponent<MovementComponent>()->get_vel() * -1);
        //Vel = Vel * -1;
        EntityManager::getInstance()->getBalls()[colliding_ball]->FindComponent<MovementComponent>()->set_vel(EntityManager::getInstance()->getBalls()[colliding_ball]->FindComponent<MovementComponent>()->get_vel() * -1);
    }

    // Rebound on margins.
    // if ((Owner->getPos().x > SCR_WIDTH) || Owner->getPos().x < 0) {
    //     Owner->setVel(vec2(Owner->getVel().x * -1.0,Owner->getVel().y));
    // }

    LimitWorldCallMsg LimitMsg;
    
    if ((Pos.x > SCR_WIDTH) || Pos.x < 0)
    {
        //Vel = vec2(Vel.x * -1.0,Vel.y);
        LimitMsg.Axis = false;
        Owner->SendMsg(&LimitMsg);
        //Owner->FindComponent<MovementComponent>()->set_vel(vec2(Owner->FindComponent<MovementComponent>()->get_vel().x * -1.f ,Owner->FindComponent<MovementComponent>()->get_vel().y));
    }
    
    // if ((Owner->getPos().y > SCR_HEIGHT) || (Owner->getPos().y < 0)) {
    //     Owner->setVel(vec2(Owner->getVel().x ,Owner->getVel().y * -1.0));
    // }
    
    if ((Pos.y > SCR_HEIGHT) || (Pos.y < 0))
    {
        LimitMsg.Axis = true;
        Owner->SendMsg(&LimitMsg);
        //Vel = vec2(Vel.x ,Vel.y * -1.0);
        //Owner->FindComponent<MovementComponent>()->set_vel(vec2(Owner->FindComponent<MovementComponent>()->get_vel().x, Owner->FindComponent<MovementComponent>()->get_vel().y * -1.f));
    }
}

void CollisionComponent::RecieveMessage(Message* Msg)
{
    NewPosMsg* PosMsg = dynamic_cast<NewPosMsg*>(Msg);
    
    if (PosMsg)
    {
        Pos = PosMsg->Pos;
        Vel = PosMsg->Vel;
    }
}
