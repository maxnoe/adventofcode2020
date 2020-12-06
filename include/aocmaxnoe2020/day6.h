#ifndef DAY4_H
#define DAY4_H

#include <string_view>
#include <string>
#include <vector>


namespace aocmaxnoe2020 { namespace day6 {

using group_t = std::vector<std::string_view>;

std::vector<group_t> parse_input(std::string_view input);
int part1(const std::vector<group_t>& groups);
int part2(const std::vector<group_t>& groups);

}}


#endif /* ifndef DAY4_H */
