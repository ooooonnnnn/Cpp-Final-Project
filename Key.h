#pragma once
#include "Item.h"

class Key : public Item
{
public:
    std::string name() override;
};
