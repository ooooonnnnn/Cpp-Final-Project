#pragma once
#include "IConfigNode.h"

class ConfigString : public IConfigNode
{
public:
    ConfigString(std::string value) : value(std::move(value)){}
    std::string value;
    std::string toString() const override;
};
