#include "ConfigSection.h"

std::string ConfigSection::toString() const
{
    std::string str;
    for (const auto& child : children)
    {
        str.append(child.first);
        str.append(" : ");
        str.append(child.second->toString());
        str.append("\n");
    }
    return str;
}
