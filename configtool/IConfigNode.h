#pragma once
#include <string>

class IConfigNode
{
public:
    virtual ~IConfigNode() = default;
    virtual std::string toString() const = 0;
};
