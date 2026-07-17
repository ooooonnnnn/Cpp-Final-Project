#include "configtool/configtool.h"
#include "Movement.h"
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
        std::cout << map.sections[position].toString();

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

        std::cout << position << "\n";
    }

    return 0;
}
