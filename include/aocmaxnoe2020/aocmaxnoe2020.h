#ifndef AOCMAXNOE2020_H
#define AOCMAXNOE2020_H

#include <string>
#include <vector>

namespace aocmaxnoe2020 {
    std::string get_input(int day);
    std::vector<std::string> split_lines(const std::string& input);
    std::vector<std::string> split(const std::string& str, const std::string& delimiter = "\n", bool include_empty=true);
}

#endif
