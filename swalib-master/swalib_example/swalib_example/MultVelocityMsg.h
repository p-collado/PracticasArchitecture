#pragma once
#include "Message.h"
class MultVelocityMsg : public Message
{
public:
  MultVelocityMsg();
  ~MultVelocityMsg();

  vec2 multValue;
};

