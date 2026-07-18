#pragma once
#include "Character.h"

class Zombie : public Character
{
public:
    Zombie();
    std::string stats_to_string() const override;
};
