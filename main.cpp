#include "configtool/configtool.h"
#include <iostream>
#include <unordered_map>

static auto map_path = "Config\\map.ini";
static auto locked_doors_path = "Config\\locked-doors.ini";
static std::unordered_map<std::string, std::string> move_commands = {
    {"up", "exit_up"},
    {"down", "exit_down"},
    {"left", "exit_left"},
    {"right", "exit_right"}
};

void try_move(ConfigData& map, ConfigData& locks, std::string& position, const std::string& direction);

int main()
{
    auto map = parse_config(map_path);
    auto locks = parse_config(locked_doors_path);

    std::string position = "0";

    
    std::cout << "\"exit\" to quit\n";
    bool exit = false;
    while (!exit)
    {
        std::cout << map.sections[position].toString();
        
        std::string input;
        std::cin >> input;
        
        if (input == "exit")
        {
            exit = true;
            continue;
        }
        
        if (move_commands.find(input) != move_commands.end())
            try_move(map, locks, position, input);
        
        std::cout << position << "\n";
    }
    
    return 0;
}

void try_move(ConfigData& map, ConfigData& locks, std::string& position, const std::string& direction)
{
    std::string next_room = map.sections[position].keys[move_commands[direction]];
    
    //check door exists
    if (next_room.empty())
    {
        std::cout << "No exit " << direction << "\n";
        return;
    }
    
    //check door not locked
    for (const auto& lock : locks.sections)
    {
        auto room = lock.second.keys.find("room");
        auto lock_dir = lock.second.keys.find("direction");
        
        if (room == lock.second.keys.end() || lock_dir == lock.second.keys.end())
            continue;
        
        if (room->second == position && lock_dir->second == direction)
        {
            std::cout << "Door locked\n";
            return;
        }
    }
    
    std::cout << "Moving " << direction << "\n";
    position = next_room;
}