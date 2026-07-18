#pragma once
#include "Character.h"

class Skeleton : public Character
{
public:
    Skeleton();
    std::string stats_to_string() const override;
};
