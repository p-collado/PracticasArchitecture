#pragma once
#include "Message.h"
class AddPositionMsg : public Message
{
public:
  AddPositionMsg();
  ~AddPositionMsg();

  vec2 addValue;
};

