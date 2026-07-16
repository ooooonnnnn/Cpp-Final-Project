#include "ConfigData.h"

std::string ConfigData::toString() const
{
    std::string str;
    for (auto& node : nodes)
    {
        str.append(node.first);
        str.append(" : ");
        str.append(node.second->toString());
        str.append("\n");   
    }
    
    return str;
}
