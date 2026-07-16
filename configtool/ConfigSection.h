#pragma once
#include <map>
#include <memory>
#include <string>

#include "IConfigNode.h"

class ConfigSection
{
public:
    std::map<std::string, std::unique_ptr<IConfigNode>> keys;
    std::string toString() const;
};
