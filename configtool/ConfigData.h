#pragma once
#include <map>
#include <string>

#include "ConfigSection.h"

class ConfigData
{
public:
    std::map<std::string, ConfigSection> sections;
    std::string toString() const;
};
