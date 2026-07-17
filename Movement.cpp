#include "Movement.h"
#include <iostream>

Movement::Movement(ConfigData& map, ConfigData& locks,
                   const std::unordered_map<std::string, std::string>& move_commands)
    : map(map), locks(locks), move_commands(move_commands) {}

bool Movement::is_door_locked(std::string& position, const std::string& direction)
{
    for (const auto& lock : locks.sections)
    {
        auto room = lock.second.keys.find("room");
        auto lock_dir = lock.second.keys.find("direction");

        if (room == lock.second.keys.end() || lock_dir == lock.second.keys.end())
            continue;

        if (room->second == position && lock_dir->second == direction)
            return true;
    }
    return false;
}

bool Movement::check_door_exists(std::string& position, const std::string& direction)
{
    std::string next_room = map.sections[position].keys[move_commands.at(direction)];
    return !next_room.empty();
}

void Movement::try_move(std::string& position, const std::string& direction)
{
    std::string next_room = map.sections[position].keys[move_commands.at(direction)];

    if (!check_door_exists(position, direction))
    {
        std::cout << "No exit " << direction << "\n";
        return;
    }

    if (is_door_locked(position, direction))
    {
        std::cout << "Door locked\n";
        return;
    }

    std::cout << "Moving " << direction << "\n";
    position = next_room;
}

void Movement::unlock_door(std::string& position, const std::string& direction)
{
    if (!check_door_exists(position, direction))
    {
        std::cout << "No door to unlock\n";
        return;
    }

    if (!is_door_locked(position, direction))
    {
        std::cout << "Door already unlocked\n";
        return;
    }

    for (const auto& lock : locks.sections)
    {
        auto room = lock.second.keys.find("room");
        auto lock_dir = lock.second.keys.find("direction");

        if (room == lock.second.keys.end() || lock_dir == lock.second.keys.end())
            continue;

        if (room->second == position && lock_dir->second == direction)
        {
            std::cout << "Unlocking door\n";
            locks.sections.erase(lock.first);
            return;
        }
    }
}
