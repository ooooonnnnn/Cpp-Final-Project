#include "ConfigData.h"

std::string ConfigData::toString() const
{
    std::string str;
    for (const auto& section : sections)
    {
        if (!section.first.empty())
        {
            str.append("[");
            str.append(section.first);
            str.append("]\n");
        }
        str.append(section.second.toString());
        str.append("\n");
    }

    return str;
}
