#ifndef day19_H
#define day19_H

#include <unordered_map>
#include <aocmaxnoe2020/aocmaxnoe2020.h>


namespace aocmaxnoe2020 { namespace day19 {

using rules_t = std::unordered_map<size_t, std::string>;

struct Input {
    rules_t rules;
    std::vector<std::string_view> messages;
};


Input parse_input(std::string_view input);
uint64_t part1(const Input& input);
uint64_t part2(const Input& input);

}}


#endif /* ifndef day19_H */
