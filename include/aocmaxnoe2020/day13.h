#ifndef day13_H
#define day13_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <vector>
#include <string_view>
#include <utility>


namespace aocmaxnoe2020 { namespace day13 {

using busses_t = std::vector<int>;

std::pair<int, busses_t> parse_input(std::string_view input);
int part1(int min_time, const busses_t& busses);
uint64_t part2(const busses_t& busses);

}}


#endif /* ifndef day13_H */
