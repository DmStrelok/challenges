#include <iostream>
#include <fstream>

#include "../utils.h"
#include "test.h"

namespace poisonous_plants {

void run_test()
{
    std::ifstream fin(INPUT_FILE);
    std::ofstream fout(OUTPUT_FILE);

    std::string n_temp;
    std::getline(fin, n_temp);

    int n = std::stoi(Utils::ltrim(Utils::rtrim(n_temp)));

    std::string p_temp_temp;
    std::getline(fin, p_temp_temp);

    std::vector<std::string> p_temp = Utils::split(Utils::rtrim(p_temp_temp));

    std::vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);
    fout << result << "\n";
    fout.close();
}

} // namespace poisonous_plants
