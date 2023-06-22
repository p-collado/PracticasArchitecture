#pragma once
#include "Message.h"
class MultPositionMsg : public Message
{
public:
  MultPositionMsg();
  ~MultPositionMsg();

  vec2 multValue;
};

