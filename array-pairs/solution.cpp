#include "solution.h"

namespace array_pairs {

int max(std::vector<int> &arr, int start, int end)
{
    int imx{arr[start]};
    std::vector<int> ind;
    ind.push_back(start);
    for (int i{start + 1}; i < end; i++)
    {
        if (imx < arr[i])
        {
            ind.clear();
            ind.push_back(i);
            imx = arr[i];
        }
        else if (imx == arr[i])
        {
            ind.push_back(i);
        }
    }
    return ind[ind.size() >> 1];
}

long count(std::vector<int> &arr, int start, int end)
{
    long cnt{0};
    int imax{start};
    if (end - start <= 1) return 0;
    else {
        imax = max(arr, start, end);
        cnt += count(arr, start, imax);
        cnt += count(arr, imax + 1, end);
        for (int i{start}, j{end - 1}; i < imax; i++)
        {
            if (arr[i] == 1)
            {
                cnt += end - imax;
                continue;
            }
            int del{arr[imax] / arr[i]};
            for (; arr[j] > del && j > imax; j--) {}
            cnt += j - imax;
        }
        if (arr[imax] == 1)
        {
            cnt += end - imax - 1;
        }
        else
        {
            for (int i{imax + 1}; i < end; i++)
            {
                if (arr[i] != 1) break;
                cnt++;
            }
        }
    }

    std::vector<int> tmp(arr.begin() + start, arr.begin() + imax + 1);
    int i{start}, s{0}, e{imax + 1};
    for (; i < end && e < end; i++)
    {
        if (tmp[s] < arr[e])
        {
            arr[i] = tmp[s];
            s++;
        }
        else
        {
            arr[i] = arr[e];
            e++;
        }
    }
    for (; i < end; i++, s++)
    {
        arr[i] = tmp[s];
    }

    return cnt;
}

long solve(std::vector<int> arr)
{
    return count(arr, 0, arr.size());
}

} // namespace array_pairs
