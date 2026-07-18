#pragma once
#include <memory>
#include <set>
#include "Item.h"
#include "Key.h"

class Inventory
{
private:
    std::set<std::shared_ptr<Item>> items;// {std::make_shared<Key>()};
public:
    template <typename T>
    bool get_item(std::shared_ptr<T>& found_item);
    template <typename T>
    std::set<std::shared_ptr<T>> get_items() const;
    void add_item(std::shared_ptr<Item> item);
    void use_item(std::shared_ptr<Item> item);
    
    std::string toString() const;
};
