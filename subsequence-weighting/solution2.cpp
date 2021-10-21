#include <map>

#include "solution2.h"

namespace subsequence_weighting {

std::uint64_t solve2(std::vector<int> a, std::vector<int> w)
{
    std::uint64_t result{0};
    std::map<int, std::uint32_t> inds;
    for (std::uint32_t i{0}; i < a.size(); i++)
    {
        inds.emplace(a[i], 0);
    }
    std::vector<std::uint64_t> max(inds.size(), 0);
    int idx{0};
    for (auto &el : inds)
    {
        el.second = idx++;
    }

    for (std::uint32_t i{0}; i < a.size(); i++)
    {
        std::uint64_t maxw{0};
        for (std::uint32_t j{inds[a[i]]}; j > 0; j -= j & (-j))
        {
            maxw = std::max(maxw, max[j]);
        }
        std::uint64_t cur{maxw + w[i]};
        result = std::max(result, cur);
        for (std::uint32_t j{inds[a[i]] + 1}; j < max.size(); j += j & (-j))
        {
            max[j] = std::max(max[j], cur);
        }
    }

    return result;
}

} // namespace subsequence_weighting
