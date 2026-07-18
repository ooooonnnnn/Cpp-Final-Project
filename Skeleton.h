#pragma once
#include "Enemy.h"

class Skeleton : public Enemy
{
public:
    Skeleton();
    std::string stats_to_string() const override;
};
