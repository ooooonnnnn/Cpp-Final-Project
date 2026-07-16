#include "configtool/configtool.h"
#include <iostream>
#include <unordered_map>

static auto map_path = "Config\\map.ini";
static std::unordered_map<std::string, std::string> move_commands = {
    {"up", "exit_up"},
    {"down", "exit_down"},
    {"left", "exit_left"},
    {"right", "exit_right"}
};

void try_move(ConfigData& map, std::string& position, const std::string& direction);

int main()
{
    auto map = parse_config(map_path);

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
            try_move(map, position, input);
        
        std::cout << position << "\n";
    }
    
    return 0;
}

void try_move(ConfigData& map, std::string& position, const std::string& direction)
{
    std::string next_room = map.sections[position].keys[move_commands[direction]];
    if (next_room.empty())
    {
        std::cout << "No exit " << direction << "\n";
    }
    else
    {
        std::cout << "Moving " << direction << "\n";
        position = next_room;
    }
}