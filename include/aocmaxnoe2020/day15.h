#ifndef day15_H
#define day15_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <utility>
#include <memory>


namespace aocmaxnoe2020 { namespace day15 {

std::vector<uint64_t> parse_input(std::string_view input);
uint64_t part1(const std::vector<uint64_t>& numbers);
uint64_t part2(const std::vector<uint64_t>& numbers);

}}


#endif /* ifndef day15_H */
