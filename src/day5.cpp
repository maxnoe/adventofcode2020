
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>
#include <utility>
#include <vector>
#include <string_view>
#include <cmath>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <bitset>


namespace aocmaxnoe2020 { namespace day5 {

using std::views::transform;

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
    return row * N_COLS + col;
}

std::pair<int, int> day5(std::string_view input) {

    std::bitset<N_SEATS> is_taken;
    int min_id = N_SEATS;
    int max_id = 0;

    std::vector<std::string_view> lines = split_lines(input);
    auto ids = lines | transform(parse_pass) | transform(pass_id);

    for (int id: ids){
        is_taken.set(id);

        if (id < min_id) {
            min_id = id;
        } else if (id > max_id) {
            max_id = id;
        }
    }

    int id;
    for (id = min_id; id < max_id; id++) {
        if (!is_taken[id]) break;
    }

    return std::make_pair(max_id, id);
}


}}

