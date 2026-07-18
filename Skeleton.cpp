#include "Skeleton.h"

Skeleton::Skeleton() : Enemy(10,8,25)
{
}

std::string Skeleton::stats_to_string() const
{
    std::stringstream ss;
    ss << "Skeleton:\n" << Character::stats_to_string();
    return ss.str();
}
