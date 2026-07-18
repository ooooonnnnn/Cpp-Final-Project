#include "Character.h"

#include <iomanip>

Character::Character(float health, float attack) : health(health), attack(attack)
{
}

void Character::take_damage(float base_damage)
{
    damage_taken += base_damage;
    if (damage_taken >= health) 
        die();
}

void Character::deal_damage_to(Character* target) const
{
    target->take_damage(attack);
}

void Character::die()
{
    is_dead = true;
}

std::string Character::stats_to_string() const
{
    std::stringstream ss;
    ss << "Health: " << std::fixed << std::setprecision(0) << health - damage_taken <<
        "/" << std::fixed << std::setprecision(0) << health << "\t" <<
            "Attack: " << std::fixed << std::setprecision(0) << attack;
    return ss.str();   
}
