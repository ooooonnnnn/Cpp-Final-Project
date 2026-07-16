#include "stringutils.h"

std::string stringutils::trim_whitespace(const std::string& str)
{
    if (str.empty()) return str;
    
    size_t start = 0;
    size_t end = 0;
    
    for (size_t i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        if (!isspace(c))
        {
            start = i;
            break;
        }
    }
    
    for (size_t i = str.size() - 1; i > start; --i)
    {
        char c = str[i];
        if (!isspace(c))
        {
            end = i;
            break;
        }
    }
    
    return str.substr(start, end - start + 1);
}
