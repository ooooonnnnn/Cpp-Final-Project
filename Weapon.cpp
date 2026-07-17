#include "Weapon.h"

Weapon::Weapon(int damage) : damage(damage){}

std::string Weapon::name()
{
    return "Weapon_" + std::to_string(damage);
}
