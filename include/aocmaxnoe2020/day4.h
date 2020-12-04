#ifndef DAY3_H
#define DAY3_H

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<string_view>


namespace aocmaxnoe2020 { namespace day4 {


const std::unordered_set<std::string> REQUIRED_KEYS_1 {
    "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
};

using passport_t = std::unordered_map<std::string, std::string>;
using passports_t = std::vector<passport_t>;

passports_t parse_input(const std::string& input);

int part1(const passports_t& passports);
long part2(const passports_t& passports);

}}


#endif /* ifndef DAY3_H */
