#include "Zombie.h"

Zombie::Zombie() : Character(5,5)
{
}

std::string Zombie::stats_to_string() const
{
    std::stringstream ss;
    ss << "Zombie:\n" << Character::stats_to_string();
    return ss.str();
}
