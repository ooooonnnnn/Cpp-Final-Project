#include "Potion.h"

Potion::Potion(int heal) : heal(heal)
{
    
}

std::string Potion::name()
{
    return "Potion_" + std::to_string(heal);
}
