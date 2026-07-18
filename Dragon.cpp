#include "Dragon.h"

Dragon::Dragon() : Character(30,15)
{
}

std::string Dragon::stats_to_string() const
{
    std::stringstream ss;
    ss << "Dragon:\n" << Character::stats_to_string();
    return ss.str();
}
