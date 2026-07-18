#include "Inventory.h"

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Key.h"
#include "Potion.h"

template <typename T>
bool Inventory::get_item(std::shared_ptr<T>& found_item)
{
    for (const auto& item : items)
    {
        auto cast_item = std::dynamic_pointer_cast<T>(item);
        if (cast_item != nullptr)
        {
            found_item = cast_item;
            return true;
        }
    }

    return false;
}

void Inventory::add_item(std::shared_ptr<Item> item)
{
    std::cout << "Adding " << item->name() << " to inventory\n";
    items.insert(item);   
}

void Inventory::use_item(std::shared_ptr<Item> item)
{
    if (items.find(item) == items.end())
    {
        throw std::runtime_error("Item not found in inventory");
    }
    
    std::cout << "Using " << item->name() << "\n";
    items.erase(item);
}

std::string Inventory::toString() const
{
    std::stringstream ss;
    ss << "Inventory: ";
    for (const auto& item : items)
    {
        ss << item->name() << " ";
    }
    return ss.str();
}

template bool Inventory::get_item<Key>(std::shared_ptr<Key>&);
template bool Inventory::get_item<Potion>(std::shared_ptr<Potion>&);
