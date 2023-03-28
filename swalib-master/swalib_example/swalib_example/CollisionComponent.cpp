#include "CollisionComponent.h"
#include "Entity.h"
#include "EntityManager.h"
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

CollisionComponent::CollisionComponent(Entity* owner)
{
    Owner = owner;
}

void CollisionComponent::Update(float elapsed)
{
    Pos = Owner->getPos();
    Vel = Owner->getVel();

    vec2 newpos = Owner->getPos()+ Owner->getVel() * elapsed;
    //vec2 newpos = Pos + Vel * elapsed;
    // Collision detection.
    bool collision = false;
    int colliding_ball = -1;
    for (int j = 0; j < EntityManager::getInstance()->getNumBalls(); j++) {
        if (Owner->getId() != j) {
            float limit2 = (Owner->getRadius() + EntityManager::getInstance()->getBalls()[j]->getRadius() * (Owner->getRadius() + EntityManager::getInstance()->getBalls()[j]->getRadius()));
            if (vlen2(newpos - EntityManager::getInstance()->getBalls()[j]->getPos()) <= limit2) {
                collision = true;
                colliding_ball = j;
                break;
            }
        }
    }
    if (!collision) {
        Owner->setPos(newpos);
        //Pos = newpos;
    }
    else {
        // Rebound!
        Owner->setVel(Owner->getVel()*-1);
        //Vel = Vel * -1;
        EntityManager::getInstance()->getBalls()[colliding_ball]->setVel(EntityManager::getInstance()->getBalls()[colliding_ball]->getVel() * -1);
    }

    // Rebound on margins.
    if ((Owner->getPos().x > SCR_WIDTH) || Owner->getPos().x < 0) {
        Owner->setVel(vec2(Owner->getVel().x * -1.0,Owner->getVel().y));
    }
    if ((Owner->getPos().y > SCR_HEIGHT) || (Owner->getPos().y < 0)) {
        Owner->setVel(vec2(Owner->getVel().x ,Owner->getVel().y * -1.0));
    }
}
