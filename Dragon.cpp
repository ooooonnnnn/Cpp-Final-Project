#include "Dragon.h"

Dragon::Dragon() : Enemy(30,15,100)
{
}

std::string Dragon::stats_to_string() const
{
    std::stringstream ss;
    ss << "Dragon:\n" << Character::stats_to_string();
    return ss.str();
}
