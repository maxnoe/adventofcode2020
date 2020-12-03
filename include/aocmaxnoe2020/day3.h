#ifndef DAY3_H
#define DAY3_H

#include<vector>
#include<string>


namespace aocmaxnoe2020 { namespace day3 {

struct Slope {
    int dx = 0;
    int dy = 0;
};

const Slope PART1_SLOPE = {.dx = 3, .dy = 1};

const std::vector<Slope> PART2_SLOPES = {
    {.dx = 1, .dy = 1},
    {.dx = 3, .dy = 1},
    {.dx = 5, .dy = 1},
    {.dx = 7, .dy = 1},
    {.dx = 1, .dy = 2},
};

using trees_t = std::vector<std::vector<bool>>;

trees_t parse_input(const std::string& input);

int trees_hit(const trees_t& trees, const Slope& slope);
int part1(const trees_t& trees);
long part2(const trees_t& trees);

}}


#endif /* ifndef DAY3_H */
