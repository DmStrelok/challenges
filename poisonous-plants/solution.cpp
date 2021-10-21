#include <stack>

#include "solution.h"

namespace poisonous_plants {

int poisonousPlants(std::vector<int> p)
{
    std::stack<std::pair<int, int>> s;
    std::pair<int, int> cur{p[p.size() - 1], 0};

    for (size_t i{p.size() - 1};;)
    {
        if (s.size() == 0 || cur.first >= s.top().first)
        {
            s.emplace(cur);
            if (i == 0) break;
            cur = std::make_pair(p[--i], 0);
            continue;
        }
        if (cur.second >= s.top().second)
        {
            s.top().second = cur.second + 1;
        }
        s.top().first = cur.first;
        cur = s.top();
        s.pop();
    }

    int result{0};
    while (s.size() > 0)
    {
        if (s.top().second > result) result = s.top().second;
        s.pop();
    }
    return result;
}

} // namespace poisonous_plants
