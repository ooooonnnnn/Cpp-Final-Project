#pragma once
#include <map>
#include <memory>
#include <string>
#include "IConfigNode.h"

class ConfigData
{
public:
    std::map<std::string, std::unique_ptr<IConfigNode>> nodes;
    std::string toString() const;
};
