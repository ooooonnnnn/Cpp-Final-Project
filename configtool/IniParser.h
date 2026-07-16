#pragma once
#include "IConfigParser.h"

class IniParser : public IConfigParser
{
    public:
        ConfigData parse(const std::string& path) override;
        void serialize(const ConfigData& configData, const std::string& path) override;
};
