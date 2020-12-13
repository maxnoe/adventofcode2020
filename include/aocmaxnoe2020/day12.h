#ifndef day12_H
#define day12_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <vector>
#include <string_view>
#include <utility>


namespace aocmaxnoe2020 { namespace day12 {

using Instruction = std::pair<char, int>;

std::vector<Instruction> parse_input(std::string_view input);
void follow_instruction(const Instruction& instruction, int& direction, std::pair<int, int>& pos);
int part1(const std::vector<Instruction>& instructions);
int part2(const std::vector<Instruction>& instructions);

}}


#endif /* ifndef day12_H */
