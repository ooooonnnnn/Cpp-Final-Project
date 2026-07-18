#pragma once
#include "Character.h"

class Player : public Character
{
    float defense;
    float xp;
    int level;
public:
    Player(float health, float attack, float defense);
    void take_damage(float base_damage) override;
    std::string stats_to_string() const override;
};
