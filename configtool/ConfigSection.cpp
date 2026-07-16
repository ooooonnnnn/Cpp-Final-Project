#include "ConfigSection.h"

std::string ConfigSection::toString() const
{
    std::string str;
    for (const auto& key : keys)
    {
        str.append(key.first);
        str.append(" : ");
        str.append(key.second);
        str.append("\n");
    }
    return str;
}
