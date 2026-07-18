#pragma once
#include "Character.h"

class Enemy : public Character
{
protected:
    float xp_value;
public:
    Enemy(float health, float attack, float xp_value);
    float get_xp_value() const;
};
