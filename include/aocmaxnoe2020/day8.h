#ifndef DAY8_H
#define DAY8_H

#include <string_view>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


namespace aocmaxnoe2020 { namespace day8 {


struct Instruction {
    std::string op;
    int arg = 0;
};

std::ostream& operator<< (std::ostream& oss, const Instruction& i);
bool operator==(const Instruction& lhs, const Instruction& rhs);


std::vector<Instruction> parse_input(std::string_view input);
int part1(const std::vector<Instruction>& program);
int part2(std::vector<Instruction> program);

}}


#endif /* ifndef DAY8_H */
