#pragma once
#include "Item.h"

class Potion : public Item
{
    int heal;
public:
    Potion(int heal);
    std::string name() override;
};
