#include "Player.h"
#include <algorithm>
#include <iomanip>

Player::Player(float health, float attack, float defense) : Character(health, attack), defense(defense)
{
    level = 0;
    xp = 0;
}

void Player::take_damage(float base_damage)
{
    Character::take_damage(base_damage / defense);
}

void Player::heal(float amount)
{
    damage_taken -= amount;
    damage_taken = std::max<float>(damage_taken, 0);
}

std::string Player::stats_to_string() const
{
    std::stringstream ss;
    ss << 
        "Health: " << std::fixed << std::setprecision(1) << health - damage_taken << "/" << 
            std::fixed << std::setprecision(1) << health << "\t" <<
        "Defense: " << std::fixed << std::setprecision(1) << defense << "\t" <<
            "Attack: " << std::fixed << std::setprecision(1) << attack;
    return ss.str();
}
