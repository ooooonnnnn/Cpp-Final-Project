#include "ConfigArray.h"

std::string ConfigArray::toString() const
{
    std::string str;
    str.append("[ ");
    size_t i = 0;
    for (const auto& node : array)
    {
        str.append(node->toString());
        if (i == array.size() - 1) continue;
        str.append(", ");
        i++;
    }
    str.append(" ]");
    return str;
}
