#include "IniParser.h"
#include <fstream>
#include <iostream>

#include "ConfigString.h"
#include "stringutils.h"

static bool is_comment(const std::string& line)
{
    if (line.empty()) return true;

    char first = line[0];
    return first == ';' || first == '#';
}

static bool is_section(const std::string& line, std::string* sectionName)
{
    if (line.empty()) return false;

    if (line[0] != '[') return false;

    if (line.back() != ']')
        throw std::runtime_error("Invalid syntax: missing closing bracket");

    if (line.size() <= 2)
        throw std::runtime_error("Invalid syntax: empty section name");

    *sectionName = line.substr(1, line.size() - 2);
    return true;
}

static void parse_key_value(const std::string& line, std::string* key, std::string* value)
{
    size_t eqSignPos = line.find('=');
    if (eqSignPos == std::string::npos)
        throw std::runtime_error("Invalid syntax: missing '='");

    *key = line.substr(0, eqSignPos);
    *value = line.substr(eqSignPos + 1);
}

ConfigData IniParser::parse(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
        throw std::runtime_error("Failed to open file");

    ConfigData data;
    data.sections[""];
    std::string currentSectionName = "";

    std::string line;

    while (std::getline(file, line))
    {
        //Parse comment
        std::string trimmed = stringutils::trim_whitespace(line);
        if (is_comment(trimmed))
            continue;

        //Parse section
        try
        {
            if (is_section(trimmed, &currentSectionName))
            {
                data.sections[currentSectionName];
                continue;
            }
        }
        catch (std::runtime_error& err)
        {
            std::cerr << "syntax error in:\n" << line << "\n"
            << err.what() << "\n";
            file.close();
            throw;
        }

        //Parse key value
        try
        {
            std::string key, value;
            parse_key_value(trimmed, &key, &value);
            data.sections[currentSectionName].keys.emplace(key, std::make_unique<ConfigString>(value));
        }
        catch (std::runtime_error& err)
        {
            std::cerr << "syntax error in:\n" << line << "\n"
            << err.what() << "\n";
            file.close();
            throw;
        }
    }

    file.close();
    return data;
}

static void serialize_section(const std::string& sectionName, const ConfigSection& section, std::ofstream& file)
{
    if (!sectionName.empty())
        file << "[" << sectionName << "]\n";

    for (const auto& key : section.keys)
    {
        file << stringutils::trim_whitespace(key.first) << "=" <<
            stringutils::trim_whitespace(key.second->toString()) << "\n";
    }
}

void IniParser::serialize(const ConfigData& configData, const std::string& path)
{
    std::ofstream file(path);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file");

    for (const auto& section : configData.sections)
    {
        serialize_section(section.first, section.second, file);
        file << "\n";
    }

    file.close();
}
