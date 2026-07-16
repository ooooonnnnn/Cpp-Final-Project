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
#include "JsonParser.h"


std::string extensionOf(const std::string& path)
{
    size_t pos = path.find_last_of('.');
    return path.substr(pos + 1);
}

std::unique_ptr<IConfigParser> makeParser(const std::string& path) {
    std::string ext = extensionOf(path);
    if (ext == "ini") return std::make_unique<IniParser>();
    if (ext == "json") return std::make_unique<JsonParser>();
    //if (ext == "xml") return std::make_unique<XmlParser>(); // bonus
    throw std::runtime_error("Unsupported format: " + ext);
}

void test_ini()
{
    auto path = "Config Files\\config.ini";
    std::unique_ptr<IConfigParser> parser = makeParser(path);
    auto data = parser->parse(path);
    std::cout << data.toString();
    
    // parser->serialize(data, path);
}

void test_json()
{
    auto path = "Config Files\\config.json";
    std::unique_ptr<IConfigParser> parser = makeParser(path);
    auto data = parser->parse(path);
    std::cout << data.toString();
}

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it = vec.end() - 1; it != vec.begin(); --it)
    {
        if (*it % 2 != 0) vec.erase(it);
    }
    
    
    
    
    // test_ini();
    //test_json();
    
    // ConfigData data;
    //
    // data.nodes.emplace("bool1", std::make_unique<ConfigBool>(true));
    // data.nodes.emplace("number1", std::make_unique<ConfigNumber>(3.14));
    //
    // ConfigSection section;
    // section.children.emplace("bool2", std::make_unique<ConfigBool>(false));
    // section.children.emplace("string 1", std::make_unique<ConfigString>("value"));
    // std::vector<std::unique_ptr<IConfigNode>> array;
    // array.emplace_back(std::make_unique<ConfigString>("1"));
    // array.emplace_back(std::make_unique<ConfigString>("2"));
    // array.emplace_back(std::make_unique<ConfigString>("3"));
    // section.children.emplace("list", std::make_unique<ConfigArray>(std::move(array)));
    // std::unique_ptr<IConfigNode> sectionPtr = std::make_unique<ConfigSection>(std::move(section));
    // data.nodes.emplace("section1", std::move(sectionPtr));
    //
    // std::cout << data.toString();
    
    return 0;
}
