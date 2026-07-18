#include "Skeleton.h"

Skeleton::Skeleton() : Character(10,8)
{
}

std::string Skeleton::stats_to_string() const
{
    std::stringstream ss;
    ss << "Skeleton:\n" << Character::stats_to_string();
    return ss.str();
}
