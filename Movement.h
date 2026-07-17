#pragma once
#include "configtool/configtool.h"
#include <string>
#include <unordered_map>

class Movement
{
public:
    Movement(ConfigData& map, ConfigData& locks,
             const std::map<std::string, std::string>& move_commands);

    void try_move(std::string& position, const std::string& direction);
    void unlock_door(std::string& position, const std::string& direction);
    bool is_door_locked(std::string& position, const std::string& direction);
    bool check_door_exists(std::string& position, const std::string& direction);

    ConfigData& map;
    ConfigData& locks;
    const std::map<std::string, std::string>& move_commands;
};
