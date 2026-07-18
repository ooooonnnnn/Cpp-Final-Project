#pragma once
#include "Item.h"

class Weapon : public Item
{
    int damage;
public:
    Weapon(int damage);
    int get_damage() const;
    std::string name() override;
};
