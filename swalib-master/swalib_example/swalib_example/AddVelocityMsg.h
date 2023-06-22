#pragma once
#include "Message.h"
class AddVelocityMsg : public Message
{
public:
  AddVelocityMsg();
  ~AddVelocityMsg();

  vec2 addValue;
};

