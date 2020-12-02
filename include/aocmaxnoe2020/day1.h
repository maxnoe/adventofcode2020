#ifndef DAY1_H
#define DAY1_H value

#include <unordered_set>
#include <string>

namespace aocmaxnoe2020 { namespace day1 {

const int TARGET = 2020;
std::unordered_set<int> parse_input(const std::string& input);
int part1(const std::unordered_set<int>& numbers);
int part2(const std::unordered_set<int>& numbers);

}}
#endif
