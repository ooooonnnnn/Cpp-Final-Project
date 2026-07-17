#pragma once
#include "Item.h"

class DummyItem : public Item
{
public:
    std::string name() override;
};
