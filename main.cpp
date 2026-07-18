#include <iostream>
#include <queue>
#include <unordered_map>

#include "DummyItem.h"
#include "configtool/configtool.h"
#include "Movement.h"
#include "Inventory.h"
#include "Player.h"
#include "Potion.h"
#include "Weapon.h"

static auto map_path = "Config\\map.ini";
static auto locked_doors_path = "Config\\locked-doors.ini";
static auto items_path = "Config\\items.ini";
static auto settings_path = "Config\\settings.ini";
static std::map<std::string, std::string> move_commands = {
    {"up", "exit_up"},
    {"down", "exit_down"},
    {"left", "exit_left"},
    {"right", "exit_right"}
};

void display_room_info(ConfigData map, std::string position)
{
    // std::cout << map.sections[position].toString();
    auto room = map.sections[position];
    std::cout << "Exits: ";
    bool first = true;
    for (auto direction : move_commands)
    {
        if (room.keys[direction.second] != "")
        {
            if (!first)
                std::cout << ", ";
            std::cout << direction.first << " ";
            
            first = false;
        }
    }
    std::cout << "\n";
}

std::shared_ptr<Item> make_item(const ConfigSection& item_data)
{
    auto type = item_data.keys.find("type");
    if (type == item_data.keys.end())
        throw std::runtime_error("Item type not found");
    
    if (type->second == "key")
        return std::make_shared<Key>();
    
    if (type->second == "weapon")
    {
        auto damage_key = item_data.keys.find("value");
        if (damage_key == item_data.keys.end())
            throw std::runtime_error("Weapon has no value field");
        int damage = std::stoi(damage_key->second);
        return std::make_shared<Weapon>(damage);
    }
    
    if (type->second == "potion")
    {
        auto heal_key = item_data.keys.find("value");
        if (heal_key == item_data.keys.end())
            throw std::runtime_error("Potion has no value field");
        int heal = std::stoi(heal_key->second);
        return std::make_shared<Potion>(heal);       
    }
    
    std::cout << "Unsupported item type: " << type->second << "\n";
    return std::make_shared<DummyItem>();
}

int main()
{
    auto map = parse_config(map_path);
    auto locks = parse_config(locked_doors_path);
    auto items = parse_config(items_path);
    auto settings = parse_config(settings_path);
    
    Movement movement(map, locks, move_commands);
    Inventory inventory;
    
    auto player_settings = settings.sections.find("player");
    float health, defense, attack;
    if (player_settings == settings.sections.end())
    {
        throw std::runtime_error("No player settings found");
    }
    health = std::stof(player_settings->second.keys["health"]);
    defense = std::stof(player_settings->second.keys["defense"]);
    attack = std::stof(player_settings->second.keys["attack"]);
    auto xp_settings = settings.sections.find("experience");
    float base_xp, xp_growth_power;
    if (xp_settings == settings.sections.end())
    {
        throw std::runtime_error("No experience settings found");
    }
    base_xp = std::stof(xp_settings->second.keys["base"]);
    xp_growth_power = std::stof(xp_settings->second.keys["growth"]);
    
    Player player(health, attack, defense);
    player.xp_for_first_lvl = base_xp;
    player.xp_growth_power = xp_growth_power;
    
    std::string position = "0";

    //game loop
    std::cout << "\"exit\" to quit\n";
    bool exit = false;
    while (!exit)
    {
        //get items from the room
        std::vector<std::string> sections_to_delete;
        for (auto& item_data : items.sections)
        {
            if (item_data.second.keys["room"] == position)
            {
                std::cout << "Found item: " << item_data.second.keys["type"] << "\n";
                inventory.add_item(make_item(item_data.second));
                sections_to_delete.push_back(item_data.first);
            }
        }
        for (auto& section_name : sections_to_delete)
        {
            items.sections.erase(section_name);
        }
        display_room_info(map, position);
        std::cout << "\033[9999;1H" << "\033[5A";
        //display player info
        std::cout << inventory.toString() << "\n" <<
            player.stats_to_string() << "\n" <<
                player.xp_to_string() << "\n";
        //move cursor up
        std::cout << "\033[10A";

        std::string input;
        std::cin >> input;

        if (input == "exit")
        {
            exit = true;
            continue;
        }

        if (move_commands.find(input) != move_commands.end())
        {
            std::cout << "\033[2J\033[1;1H";
            movement.try_move(position, input);
            continue;
        }

        if (input == "unlock")
        {
            //get direction of door to unlock
            std::string unlock_dir;
            std::cin >> unlock_dir;
            if (move_commands.find(unlock_dir) == move_commands.end())
            {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "Invalid direction\n";
                continue;
            }
            
            //check if player has key
            std::shared_ptr<Key> key;
            if (!inventory.get_item<Key>(key))
            {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "No key\n";
                continue;
            }
            
            std::cout << "\033[2J\033[1;1H";
            if (movement.unlock_door(position, unlock_dir))
            {
                inventory.use_item(key);
            }
            continue;
        }
        
        if (input == "heal")
        {
            //check if player has potion
            std::shared_ptr<Potion> found_potion;
            if (!inventory.get_item<Potion>(found_potion))
            {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "No potion\n";
                continue;
            }
            
            std::cout << "\033[2J\033[1;1H";
            player.heal(found_potion->heal_amount());
            inventory.use_item(found_potion);
            continue;
        }
        
        std::cout << "\033[2J\033[1;1H";
    }

    return 0;
}
