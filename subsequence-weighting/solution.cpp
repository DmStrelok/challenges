#include <map>
#include <functional>

#include "solution.h"

namespace subsequence_weighting {

std::uint64_t solve(std::vector<int> a, std::vector<int> w)
{
    using multimap = std::multimap<std::uint64_t, int, std::greater<std::uint64_t>>;
    std::map<int, std::pair<std::uint64_t, multimap::iterator>> key_max;
    multimap max_key;

    for (int i{0}; i < a.size(); i++)
    {
        std::uint64_t cur_w = w[i];
        for (auto &max : max_key)
        {
            if (max.second >= a[i]) continue;
            cur_w += max.first;
            break;
        }

        auto exist = key_max.find(a[i]);
        if (exist == key_max.end())
        {
            auto x = max_key.emplace(cur_w, a[i]);
            key_max.emplace(a[i], std::make_pair(cur_w, x));
        }
        else
        {
            if (exist->second.first >= cur_w) continue;
            max_key.erase(exist->second.second);
            auto x = max_key.emplace(cur_w, a[i]);
            exist->second.first = cur_w;
            exist->second.second = x;
        }
    }
    return max_key.begin()->first;
}

} // namespace subsequence_weighting
