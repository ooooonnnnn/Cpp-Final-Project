#include "configtool/configtool.h"
#include <iostream>

static auto map_path = "Config\\map.ini";

int main()
{
    auto map = parse_config(map_path);
    std::string position = "0";

    
    std::cout << "\"exit\" to quit\n";
    bool exit = false;
    while (!exit)
    {
        std::string input;
        std::cin >> input;
        
        if (input == "exit")
        {
            exit = true;
            continue;
        }
    }
    
    return 0;
}