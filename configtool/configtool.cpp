#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <vector>

#include "ConfigArray.h"
#include "ConfigBool.h"
#include "ConfigNumber.h"
#include "ConfigSection.h"
#include "ConfigString.h"
#include "IConfigParser.h"
#include "IniParser.h"


std::string extensionOf(const std::string& path)
{
    size_t pos = path.find_last_of('.');
    return path.substr(pos + 1);
}

std::unique_ptr<IConfigParser> makeParser(const std::string& path) {
    std::string ext = extensionOf(path);
    if (ext == "ini") return std::make_unique<IniParser>();
    //if (ext == "xml") return std::make_unique<XmlParser>(); // bonus
    throw std::runtime_error("Unsupported format: " + ext);
}

void test_ini()
{
    auto path = "Config\\map.ini";
    std::unique_ptr<IConfigParser> parser = makeParser(path);
    auto data = parser->parse(path);
    std::cout << data.toString();
    
    // parser->serialize(data, path);
}

int test(int argc, char* argv[])
{
    test_ini();
    
    return 0;
}

ConfigData parse_config(const std::string& path)
{
    std::unique_ptr<IConfigParser> parser = makeParser(path);
    return parser->parse(path);
}
