#ifndef DAY7_H
#define DAY7_H

#include <string_view>
#include <string>
#include <vector>
#include <unordered_map>


namespace aocmaxnoe2020 { namespace day7 {

using contents_t = std::unordered_map<std::string, int>;
using rules_t = std::unordered_map<std::string, contents_t>;

rules_t parse_input(std::string_view input);
int part1(const rules_t& rules);
int part2(const rules_t& rules);

}}


#endif /* ifndef DAY7_H */
