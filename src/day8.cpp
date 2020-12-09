#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day8.h>
#include <vector>
#include <string_view>
#include <bitset>

namespace aocmaxnoe2020 { namespace day8 {


std::ostream& operator<< (std::ostream& oss, const Instruction& i) {
    oss << i.op << "(" << i.arg << ")"; 
    return oss;
}

bool operator==(const Instruction& lhs, const Instruction& rhs) {
    return (lhs.op == rhs.op) && (lhs.arg == rhs.arg);
}

std::vector<Instruction> parse_input(std::string_view input){
    auto lines = split_lines(input);
    std::vector<Instruction> program;
    program.reserve(lines.size());
    for (auto line: lines) {
        program.emplace_back(
            std::string{line.substr(0, 3)},
            std::stoi(std::string{line.substr(3, line.size())})
        );
    }
    return program;
}


std::pair<bool, int> execute_program(const std::vector<Instruction>& program) {
    int accumulator = 0;
    size_t pos = 0;
    std::vector<bool> visited(program.size(), false);

    while (pos < program.size()) {
        const auto& instruction = program.at(pos);

        if (visited.at(pos)) return std::make_pair(false, accumulator);
        visited[pos] = true;

        if (instruction.op == "jmp") {
            pos += instruction.arg;
            continue;
        }

        if (instruction.op == "acc") {
            accumulator += instruction.arg;
        }

        pos++;
    }

    return std::make_pair(true, accumulator);
}


int part1(const std::vector<Instruction>& program) {
    auto [terminated, acc] = execute_program(program); 
    return acc;
}


int part2(std::vector<Instruction> program) {
    for (size_t idx = 0; idx < program.size(); idx++) {
        auto& instruction = program.at(idx);
       
        // acc are correct
        if (instruction.op == "acc") continue;

        std::string before = instruction.op;
        if (before == "nop") {
            instruction.op = "jmp";
        } else {
            instruction.op = "nop";
        }


        auto [terminated, acc] = execute_program(program);

        instruction.op = before;

        if (terminated) return acc;
    }
    return -1;
}

}}

