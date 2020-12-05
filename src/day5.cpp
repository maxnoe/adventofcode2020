
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>
#include <utility>
#include <vector>
#include <string_view>
#include <cmath>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <unordered_set>


namespace aocmaxnoe2020 { namespace day5 {


std::vector<boarding_pass_t> parse_input(std::string_view input) {
    auto lines = split_lines(input);
    std::vector<boarding_pass_t> boarding_passes;
    boarding_passes.reserve(lines.size());

    for (std::string_view line: lines) {
        boarding_passes.push_back(parse_pass(line));
    }
    return boarding_passes;
}


int binary_search(std::string_view tokens) {
    int min = 0;
    int max = (1 << tokens.size()) - 1;
    int midpoint;

    for (auto token: tokens) {
        midpoint = (min + max) / 2;

        if (token == 'F' || token == 'L') {
            max = midpoint;
        } else {
            min = midpoint + 1;
        }
    }

    return max;

}


boarding_pass_t parse_pass(std::string_view line) {
    int row = binary_search(line.substr(0, 7));
    int col = binary_search(line.substr(7, 10));
    return std::make_pair(row, col);
}

int pass_id(const boarding_pass_t& pass) {
    auto [row, col] = pass;
    return row * 8 + col;
}


int part1(const std::vector<boarding_pass_t>& boarding_passes) {
    return std::ranges::max(boarding_passes | std::views::transform(pass_id));
    
}
int part2(const std::vector<boarding_pass_t>& boarding_passes) {
    
    std::unordered_set<int> ids;
    ids.reserve(boarding_passes.size());
    for (const boarding_pass_t& pass: boarding_passes) {
        ids.insert(pass_id(pass));
    }

    for (int row = 0; row < 128; row++) {
        for (int col = 0; col < 8; col++) {
            int id = pass_id(std::make_pair(row, col));

            if (!ids.contains(id) && ids.contains(id - 1) && ids.contains(id + 1)) {
                return id;
            }
        }
    }

    throw std::runtime_error("Did not find free seat");

    return 0;
}


}}

