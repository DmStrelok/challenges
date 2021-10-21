#include <iostream>
#include <fstream>
#include <functional>
#include <cctype>
#include <vector>

#include "poisonous-plants/solution.h"

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

int main()
{
    std::ifstream fin(poisonous_plants::INPUT_FILE);
    std::ofstream fout(poisonous_plants::OUTPUT_FILE);

    std::string n_temp;
    std::getline(fin, n_temp);

    int n = std::stoi(ltrim(rtrim(n_temp)));

    std::string p_temp_temp;
    std::getline(fin, p_temp_temp);

    std::vector<std::string> p_temp = split(rtrim(p_temp_temp));

    std::vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonous_plants::poisonousPlants(p);

    fout << result << "\n";

    fout.close();

    return 0;
}

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());

    return s;
}

std::vector<std::string> split(const std::string &str) {
    std::vector<std::string> tokens;

    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
