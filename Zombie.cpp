#include "Zombie.h"

Zombie::Zombie() : Enemy(5,5,10)
{
}

std::string Zombie::stats_to_string() const
{
    std::stringstream ss;
    ss << "Zombie:\n" << Character::stats_to_string();
    return ss.str();
}
