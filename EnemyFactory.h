#pragma once
#include "Character.h"

class EnemyFactory
{
public:
    static Character* make_enemy(std::string enemy_type);
};
