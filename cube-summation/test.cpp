#include <iostream>
#include <fstream>

#include "../utils.h"
#include "test.h"

namespace cube_summation {

void run_test(std::vector<long> (*cubeSum) (int, std::vector<std::string>))
{
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::string T_temp;
    std::getline(fin, T_temp);

    int T = std::stoi(Utils::ltrim(Utils::rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        std::string first_multiple_input_temp;
        std::getline(fin, first_multiple_input_temp);
        std::vector<std::string> first_multiple_input = Utils::split(Utils::rtrim(first_multiple_input_temp));

        int matSize = stoi(first_multiple_input[0]);
        int m = stoi(first_multiple_input[1]);
        std::vector<std::string> ops(m);

        for (int i = 0; i < m; i++) {
            std::string ops_item;
            std::getline(fin, ops_item);
            ops[i] = ops_item;
        }

        std::vector<long> res = cubeSum(matSize, ops);

        for (size_t i = 0; i < res.size(); i++)
        {
            fout << res[i];
            if (i != res.size() - 1)
            {
                fout << "\n";
            }
        }
        fout << "\n";
    }
    fout.close();
}

} // namespace cube_summation
