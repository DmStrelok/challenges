#include <iostream>
#include <fstream>

#include "../utils.h"
#include "test.h"

namespace array_pairs {

void run_test(long (*solve) (std::vector<int>))
{
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::string arr_count_temp;
    std::getline(fin, arr_count_temp);
    int arr_count = std::stoi(Utils::ltrim(Utils::rtrim(arr_count_temp)));

    std::string arr_temp_temp;
    std::getline(fin, arr_temp_temp);
    std::vector<std::string> arr_temp = Utils::split(Utils::rtrim(arr_temp_temp));
    std::vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++)
    {
        int arr_item = std::stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    fout << solve(arr) << "\n";
    fout.close();
}

} // namespace array_pairs
