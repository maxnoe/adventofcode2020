#ifndef day16_H
#define day16_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <iostream>
#include <utility>
#include <memory>


namespace aocmaxnoe2020 { namespace day16 {


struct Specification {
    int min1 = 0;
    int max1 = 0;
    int min2 = 0;
    int max2 = 0;

    bool validate(int v) const {
        bool r = ((min1 <= v) && (v <= max1)) || ((min2 <= v) && (v <= max2));
        return r;
    }
};

using Ticket = std::vector<int>;

struct Input {
    std::unordered_map<std::string, Specification> specifications;
    Ticket my_ticket;
    std::vector<Ticket> nearby_tickets;
};

Input parse_input(std::string_view input);
uint64_t part1(const Input& input);
uint64_t part2(const Input& input);

}}


#endif /* ifndef day16_H */
