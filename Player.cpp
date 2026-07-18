#include "Player.h"
#include <algorithm>
#include <iomanip>
#include <cmath>

#include "Weapon.h"

Player::Player(float health, float attack, float defense) : Character(health, attack), defense(defense)
{
    level = 0;
    xp = 0;
    modified_attack = attack;
    modified_defense = defense;
}

void Player::take_damage(float base_damage)
{
    Character::take_damage(base_damage / modified_defense);
}

void Player::deal_damage_to(Character* target) const
{
    target->take_damage(modified_attack);
}

void Player::heal(float amount)
{
    damage_taken -= amount;
    damage_taken = std::max<float>(damage_taken, 0);
}

float Player::xp_for_next_lvl() const
{
    return xp_for_first_lvl * std::exp(xp_growth_power * level);
}

void Player::gain_xp(float amount)
{
    xp += amount;
    while (xp >= xp_for_next_lvl())
    {
        xp -= xp_for_next_lvl();
        level++;
        update_stats(nullptr);
    }   
}

void Player::update_stats(Inventory* inventory)
{
    //update by the level
    float factor = 1.5;
    modified_defense = defense * static_cast<float>(pow(factor, level));
    modified_attack = attack * static_cast<float>(pow(factor, level));
    
    if (inventory == nullptr)
    {
        inventory = this->inventory;
    }
    
    if (inventory == nullptr)
        return;
    
    this->inventory = inventory;
    
    auto weapons = inventory->get_items<Weapon>();
    for (auto& weapon : weapons)
    {
        modified_attack += weapon->get_damage();
    }
}

std::string Player::stats_to_string() const
{
    std::stringstream ss;
    ss << 
        "Health: " << std::fixed << std::setprecision(1) << health - damage_taken << "/" << 
            std::fixed << std::setprecision(1) << health << "\t" <<
        "Defense: " << std::fixed << std::setprecision(1) << modified_defense << "\t" <<
            "Attack: " << std::fixed << std::setprecision(1) << modified_attack;
    return ss.str();
}

std::string Player::xp_to_string() const
{
    std::stringstream ss;
    ss << 
        "Level: " << std::fixed << std::setprecision(0) << level << "\t" <<
        "Experience: " << std::fixed << std::setprecision(0) << xp << "/" << 
            std::fixed << std::setprecision(1) << xp_for_next_lvl();
    return ss.str();
}
