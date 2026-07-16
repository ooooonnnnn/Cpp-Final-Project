#pragma once
#include <memory>
#include <vector>

#include "IConfigNode.h"

class ConfigArray : public IConfigNode
{
public:
    ConfigArray(std::vector<std::unique_ptr<IConfigNode>> array) : array(std::move(array)){}
    std::vector<std::unique_ptr<IConfigNode>> array;
    std::string toString() const override;
};
