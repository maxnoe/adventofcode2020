#ifndef DAY9_H
#define DAY9_H

#include <string_view>
#include <string>
#include <vector>
#include <unordered_map>


namespace aocmaxnoe2020 { namespace day9 {

std::vector<uint64_t> parse_input(std::string_view input);
int part1(const std::vector<uint64_t>& numbers, size_t buffer_size);
int part2(const std::vector<uint64_t>& numbers, uint64_t target);

}}


#endif /* ifndef DAY9_H */
