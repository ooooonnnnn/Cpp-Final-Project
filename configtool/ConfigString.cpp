#include "ConfigString.h"

std::string ConfigString::toString() const
{
    return "\"" + value + "\"";
}
