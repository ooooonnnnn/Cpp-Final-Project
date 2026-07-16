#pragma once
#include "IConfigNode.h"

class ConfigNumber : public IConfigNode
{
public:
    double value;
    ConfigNumber(double value) : value(value){}
    std::string toString() const override;
};
