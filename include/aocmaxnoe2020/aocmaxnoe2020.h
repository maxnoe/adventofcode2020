#ifndef AOCMAXNOE2020_H
#define AOCMAXNOE2020_H

#include <string>
#include <vector>
#include <string_view>

namespace aocmaxnoe2020 {
    std::string get_input(int day);
    std::vector<std::string_view> split_lines(std::string_view input);
    std::vector<std::string_view> split(std::string_view str, std::string_view delimiter = "\n", bool include_empty=true);
}

#endif
