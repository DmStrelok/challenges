#ifndef __UTILS_SOLUTION_H__
#define __UTILS_SOLUTION_H__

#include <vector>
#include <string>

class Utils
{
public:
    static std::string ltrim(const std::string &);
    static std::string rtrim(const std::string &);
    static std::vector<std::string> split(const std::string &);
};

#endif // __UTILS_SOLUTION_H__
