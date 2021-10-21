#include <map>
#include <string>

#include "../utils.h"
#include "solution2.h"

namespace cube_summation {

std::vector<long> cubeSum2(int n, std::vector<std::string> operations)
{
    std::vector<long> result;
    std::vector<std::vector<std::vector<std::pair<long, long>>>> data(n + 1);
    for (auto &el : data)
    {
        el.resize(n + 1);
        for (auto &el2 : el)
        {
            el2.resize(n + 1, {0, 0});
        }
    }

    for (const std::string &operation : operations)
    {
        std::vector<std::string> request = Utils::split(operation);
        if (request[0] == "UPDATE")
        {
            int x{std::atoi(request[1].c_str())};
            int y{std::atoi(request[2].c_str())};
            int z{std::atoi(request[3].c_str())};
            long w{std::atoi(request[4].c_str()) - data[x][y][z].first};
            data[x][y][z].first += w;
            for (int i{x}; i <= n; i++)
            {
                for (int j{y}; j <= n; j++)
                {
                    for (int k{z}; k <= n; k++)
                    {
                        data[i][j][k].second += w;
                    }
                }
            }
        }
        else if (request[0] == "QUERY")
        {
            int x1{std::atoi(request[1].c_str()) - 1};
            int y1{std::atoi(request[2].c_str()) - 1};
            int z1{std::atoi(request[3].c_str()) - 1};

            int x2{std::atoi(request[4].c_str())};
            int y2{std::atoi(request[5].c_str())};
            int z2{std::atoi(request[6].c_str())};

            long sum{0};
            sum = data[x2][y2][z2].second - data[x1][y1][z1].second
                - data[x1][y2][z2].second - data[x2][y1][z2].second - data[x2][y2][z1].second
                + data[x1][y1][z2].second + data[x1][y2][z1].second + data[x2][y1][z1].second;
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
