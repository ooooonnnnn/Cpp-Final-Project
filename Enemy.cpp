#include "Enemy.h"

Enemy::Enemy(float health, float attack, float xp_value) : Character(health, attack), xp_value(xp_value)
{
}

float Enemy::get_xp_value() const
{
    return xp_value;
}
