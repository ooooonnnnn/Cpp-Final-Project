#include "Inventory.h"

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "HolyGrail.h"
#include "Key.h"
#include "Potion.h"
#include "Weapon.h"

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

template <typename T>
std::set<std::shared_ptr<T>> Inventory::get_items() const
{
    std::set<std::shared_ptr<T>> found_items;
    
    for (auto& item : items)
    {
        auto cast_item = std::dynamic_pointer_cast<T>(item);
        if (cast_item != nullptr)
        {
            found_items.insert(cast_item);
        }
    }
    
    return found_items;
}

template std::set<std::shared_ptr<Weapon>> Inventory::get_items() const;

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
template bool Inventory::get_item<HolyGrail>(std::shared_ptr<HolyGrail>&);
