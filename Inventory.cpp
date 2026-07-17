#include "Inventory.h"

#include <iostream>
#include <stdexcept>

#include "Key.h"

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

void Inventory::use_item(std::shared_ptr<Item> item)
{
    if (items.find(item) == items.end())
    {
        throw std::runtime_error("Item not found in inventory");
    }
    
    std::cout << "Using " << item->name() << "\n";
    items.erase(item);
}

template bool Inventory::get_item<Key>(std::shared_ptr<Key>&);
