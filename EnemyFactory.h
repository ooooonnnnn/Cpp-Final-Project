#pragma once
#include "Enemy.h"

class EnemyFactory
{
public:
    static Enemy* make_enemy(std::string enemy_type);
};
