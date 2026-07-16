#include "JsonParser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum Chars
{
    OBJ_START = '{',
    OBJ_END = '}',
    ARRAY_START = '[',
    ARRAY_END = ']',
    SEPARATOR = ':'
};

enum State
{
    StartObj,
    String
};

void skip_whitespace(std::ifstream& file, char& ch)
{
    while (file.get(ch))
    {
        if (!std::isspace(ch))
            break;
    }
}

void read_string(std::ifstream& file, std::string& str, char& ch)
{
    if (ch != '"') std::cerr << "Wrong character";
    while (file.get(ch))
    {
        if (ch != '"') 
            str.push_back(ch);
        else break;
    }
}

void read_object(std::ifstream& file, ConfigData& data, char& ch)
{
    std::cout << ch;
    if (ch != OBJ_START)
        std::cerr << "Wrong character";
    skip_whitespace(file, ch);
    std::string key;
    read_string(file, key, ch);
    skip_whitespace(file, ch);
    if (ch != SEPARATOR)
        std::cerr << "Wrong character";
    skip_whitespace(file, ch);
    if (std::isdigit(ch))
    while
}

ConfigData JsonParser::parse(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file");
    
    ConfigData data;
    char ch;
    
    // std::ostringstream buffer;
    // buffer << file.rdbuf();
    // std::string content = buffer.str();
    // size_t i = 0;
    
    while (file.get(ch))
    {
        read_object(file, data, ch);
    }
    
    file.close();
}

void JsonParser::serialize(const ConfigData& configData, const std::string& path)
{
}
