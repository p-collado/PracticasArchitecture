#pragma once

#include "Message.h"


class BallGravityMsg : public Message
{
public:
  BallGravityMsg();
  ~BallGravityMsg();


  vec2 gravity;
};

