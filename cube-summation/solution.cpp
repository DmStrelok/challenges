#include <map>

#include "../utils.h"
#include "solution.h"

namespace cube_summation {

std::vector<long> cubeSum(int n, std::vector<std::string> operations)
{
    std::vector<long> result;
    std::map<int, long> data;

    for (const std::string &operation : operations)
    {
        std::vector<std::string> request = Utils::split(operation);
        if (request[0] == "UPDATE")
        {
            data[(std::atoi(request[1].c_str()) << 16) +
            (std::atoi(request[2].c_str()) << 8) +
            std::atoi(request[3].c_str())] = std::atoi(request[4].c_str());
        }
        else if (request[0] == "QUERY")
        {
            int z1{std::atoi(request[3].c_str())};
            int yz1{z1 + (std::atoi(request[2].c_str()) << 8)};
            int xyz1{yz1 + (std::atoi(request[1].c_str()) << 16)};

            int z2{std::atoi(request[6].c_str())};
            int yz2{z2 + (std::atoi(request[5].c_str()) << 8)};
            int xyz2{yz2 + (std::atoi(request[4].c_str()) << 16)};

            long sum{0};
            for (const auto &el : data)
            {
                if (el.first > xyz2) break;
                if (xyz1 <= el.first
                    && yz1 <= (el.first & 0xFFFF) && (el.first & 0xFFFF) <= yz2
                    && z1 <= (el.first & 0xFF) && (el.first & 0xFF) <= z2)
                {
                    sum += el.second;
                }
            }
            result.push_back(sum);
        }
        else
        {
            data.clear();
        }
    }
    return result;
}

} // namespace cube_summation
