#pragma once
#include "Character.h"

class Dragon : public Character
{
public:
    Dragon();
    std::string stats_to_string() const override;
};
