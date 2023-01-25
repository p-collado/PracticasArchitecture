#include "ball.h"
#include "../../common/sys.h"
#include "../../common/core.h"
#include "EntityManager.h"
#include <vector>


Sprite& ball::getSpriteref()
{
	return renderinfo;
}

void ball::setRadius(float _radius)
{
	radius = _radius;
}

void ball::setPos(vec2 _pos)
{
	pos = _pos;
}

void ball::setVel(vec2 _vel)
{
	vel = _vel;
}

void ball::Slot(double _elapsed)
{
	// Run balls
		// New Pos.
	vec2 newpos = pos + vel * _elapsed;

	renderinfo.setPos(newpos);

	// Collision detection.
	bool collision = false;
	int colliding_ball = -1;
	for (int j = 0; j < EntityManager::getInstance()->getNumBalls(); j++) {
		if (id != j) {
			float limit2 = (radius + EntityManager::getInstance()->getBalls()[j]->getRadius() * (radius + EntityManager::getInstance()->getBalls()[j]->getRadius()));
			if (vlen2(newpos - EntityManager::getInstance()->getBalls()[j]->getPos()) <= limit2) {
				collision = true;
				colliding_ball = j;
				break;
			}
		}
	}
	if (!collision) {
		pos = newpos;
	}
	else {
		// Rebound!
		vel *= -1.f;
		EntityManager::getInstance()->getBalls()[colliding_ball]->getVel() *= -1.f;
	}

	// Rebound on margins.
	if ((pos.x > SCR_WIDTH) || pos.x < 0) {
		vel.x *= -1.0;
	}
	if ((pos.y > SCR_HEIGHT) || (pos.y < 0)) {
		vel.y *= -1.0;
	}
}

ball::ball(int _id, const char* filename) : renderinfo(filename, false)
{
	float MAX_BALL_SPEED = EntityManager::getInstance()->getSpeed();
	id = _id;
	pos = (vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)));
	vel = (vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED)));
	radius = 16.f;
	renderinfo.setSize(vec2(radius * 2, radius * 2));
}