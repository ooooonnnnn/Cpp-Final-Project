#pragma once
#include "Character.h"

class Player : public Character
{
    float defense;
    float xp;
    int level;
public:
    float xp_for_first_lvl;
    float xp_growth_power;
    
    Player(float health, float attack, float defense);
    void take_damage(float base_damage) override;
    void heal(float amount);
    float xp_for_next_lvl() const;
    void gain_xp(float amount);
    
    std::string stats_to_string() const override;
    std::string xp_to_string() const;
};
