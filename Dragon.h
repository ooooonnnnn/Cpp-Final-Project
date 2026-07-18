#pragma once
#include "Enemy.h"

class Dragon : public Enemy
{
public:
    Dragon();
    std::string stats_to_string() const override;
};
