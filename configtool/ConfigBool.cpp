#include "ConfigBool.h"

std::string ConfigBool::toString() const
{
    return value ? "true" : "false";
}
