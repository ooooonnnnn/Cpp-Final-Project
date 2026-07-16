#pragma once
#include <map>
#include <memory>

#include "IConfigNode.h"

class ConfigSection : public IConfigNode
{
public:
    std::map<std::string, std::unique_ptr<IConfigNode>> children;
    std::string toString() const override;
};
