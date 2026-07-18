#pragma once
#include "Enemy.h"

class Zombie : public Enemy
{
public:
    Zombie();
    std::string stats_to_string() const override;
};
