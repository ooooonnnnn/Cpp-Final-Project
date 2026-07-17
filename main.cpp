#include "configtool/configtool.h"
#include "Movement.h"
#include <iostream>
#include <unordered_map>

static auto map_path = "Config\\map.ini";
static auto locked_doors_path = "Config\\locked-doors.ini";
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

int main()
{
    auto map = parse_config(map_path);
    auto locks = parse_config(locked_doors_path);

    Movement movement(map, locks, move_commands);

    std::string position = "0";

    //game loop
    std::cout << "\"exit\" to quit\n";
    bool exit = false;
    while (!exit)
    {
        display_room_info(map, position);

        std::string input;
        std::cin >> input;

        if (input == "exit")
        {
            exit = true;
            continue;
        }

        if (move_commands.find(input) != move_commands.end())
            movement.try_move(position, input);

        if (input == "unlock")
        {
            std::string unlock_dir;
            std::cin >> unlock_dir;
            if (move_commands.find(unlock_dir) == move_commands.end())
            {
                std::cout << "Invalid direction\n";
                continue;
            }
            movement.unlock_door(position, unlock_dir);
        }
    }

    return 0;
}
