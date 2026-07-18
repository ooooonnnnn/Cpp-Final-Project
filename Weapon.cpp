#include "Weapon.h"

Weapon::Weapon(int damage) : damage(damage){}

int Weapon::get_damage() const
{
    return damage;
}

std::string Weapon::name()
{
    return "Weapon_" + std::to_string(damage);
}
