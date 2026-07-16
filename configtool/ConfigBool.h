#pragma once
#include "IConfigNode.h"

class ConfigBool : public IConfigNode
{
public:
    ConfigBool(bool value) : value(value){}
    std::string toString() const override;

private:
    bool value;
};
