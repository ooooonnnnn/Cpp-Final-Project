#pragma once
#include <map>
#include <string>

class ConfigSection
{
public:
    std::map<std::string, std::string> keys;
    std::string toString() const;
};
