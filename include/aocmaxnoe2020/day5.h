#ifndef DAY3_H
#define DAY3_H

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<string_view>


namespace aocmaxnoe2020 { namespace day5 {

using boarding_pass_t = std::pair<int, int>;


std::vector<boarding_pass_t> parse_input(std::string_view input);
boarding_pass_t parse_pass(std::string_view line);
int pass_id(const boarding_pass_t& pass);
int part1(const std::vector<boarding_pass_t>& boarding_passes);
int part2(const std::vector<boarding_pass_t>& boarding_passes);

}}


#endif /* ifndef DAY3_H */
