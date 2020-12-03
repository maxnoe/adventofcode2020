
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day3.h>
#include <iostream>


namespace aocmaxnoe2020 { namespace day3 {


trees_t parse_input(const std::string& input) {
    std::vector<std::string> lines = split_lines(input);

    trees_t trees;
    trees.reserve(lines.size());

    for (const std::string& line: lines) {
        trees.emplace_back();
        trees.back().reserve(line.size());

        for (const char& pos: line) {
            trees.back().push_back(pos == '#');
        }
    }

    return trees;
}

int trees_hit(const trees_t& trees, const Slope& slope) {
    size_t x = 0;
    size_t y = 0;
    int hits = 0;

    while (y < trees.size()) {
        const auto& row = trees.at(y);
        if (row.at(x % row.size())) {
            hits++;
        }

        x += slope.dx;
        y += slope.dy;
    }

    return hits;
}


int part1(const trees_t& trees) {
    return trees_hit(trees, PART1_SLOPE);
}

long part2(const trees_t& trees) {
    long result = 1;
    for (const Slope& slope: PART2_SLOPES) {
        result *= trees_hit(trees, slope);
    }
    return result;
}

}}

