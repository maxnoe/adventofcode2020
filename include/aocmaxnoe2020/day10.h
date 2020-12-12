#ifndef day10_H
#define day10_H

#include <string_view>
#include <string>
#include <vector>
#include <unordered_map>


namespace aocmaxnoe2020 { namespace day10 {

std::vector<uint64_t> parse_input(std::string_view input);

std::vector<uint64_t> diff(const std::vector<uint64_t>& numbers);


uint64_t part1(const std::vector<uint64_t>& numbers);
uint64_t part2(const std::vector<uint64_t>& numbers);

}}


#endif /* ifndef day10_H */
