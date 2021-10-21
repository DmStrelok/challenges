#include <iostream>
#include <fstream>

#include "../utils.h"
#include "test.h"

namespace subsequence_weighting {

void run_test(std::uint64_t (*solve) (std::vector<int>, std::vector<int>))
{
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::string t_temp;
    std::getline(fin, t_temp);
    int t = std::stoi(Utils::ltrim(Utils::rtrim(t_temp)));
    for (int t_itr = 0; t_itr < t; t_itr++) {
        std::string n_temp;
        std::getline(fin, n_temp);

        int n = std::stoi(Utils::ltrim(Utils::rtrim(n_temp)));
        std::string a_temp_temp;
        std::getline(fin, a_temp_temp);

        std::vector<std::string> a_temp = Utils::split(Utils::rtrim(a_temp_temp));
        std::vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = std::stoi(a_temp[i]);
            a[i] = a_item;
        }

        std::string w_temp_temp;
        std::getline(fin, w_temp_temp);
        std::vector<std::string> w_temp = Utils::split(Utils::rtrim(w_temp_temp));
        std::vector<int> w(n);

        for (int i = 0; i < n; i++) {
            int w_item = std::stoi(w_temp[i]);
            w[i] = w_item;
        }
        long long result = solve(a, w);
        fout << result << "\n";
    }
    fout.close();
}

} // namespace subsequence_weighting
