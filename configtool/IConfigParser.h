#pragma once
#include <map>
#include <string>
#include "ConfigData.h"

class IConfigParser
{
public:
    virtual ~IConfigParser() = default;
    virtual ConfigData parse(const std::string& path) = 0;
    virtual void serialize(const ConfigData& configData, const std::string& path) = 0;
};