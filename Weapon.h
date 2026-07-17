#pragma once
#include "Item.h"

class Weapon : public Item
{
    int damage;
public:
    Weapon(int damage);
    std::string name() override;
};
