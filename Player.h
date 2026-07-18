#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
    float modified_attack;
    float defense;
    float modified_defense;
    float xp;
    int level;
    Inventory* inventory = nullptr;
public:
    float xp_for_first_lvl;
    float xp_growth_power;
    
    Player(float health, float attack, float defense);
    void take_damage(float base_damage) override;
    void deal_damage_to(Character* target) const override;
    void heal(float amount);
    float xp_for_next_lvl() const;
    void gain_xp(float amount);
    void update_stats(Inventory* inventory);
    
    std::string stats_to_string() const override;
    std::string xp_to_string() const;
};
