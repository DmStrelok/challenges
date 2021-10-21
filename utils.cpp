#include "utils.h"

std::string Utils::ltrim(const std::string &str)
{
    std::string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }));

    return s;
}

std::string Utils::rtrim(const std::string &str)
{
    std::string s(str);

    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }).base(), s.end());

    return s;
}

std::vector<std::string> Utils::split(const std::string &str)
{
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));

    return tokens;
}
