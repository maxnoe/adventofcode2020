#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day12.h>
#include <vector>
#include <ranges>

namespace aocmaxnoe2020 { namespace day12 {


std::vector<Instruction> parse_input(std::string_view input) {
    auto lines = split_lines(input);
    std::vector<Instruction> instructions;
    instructions.reserve(lines.size());

    for (auto line: lines) {
        int amount = std::stoi(std::string{line.substr(1, line.size())});
        instructions.emplace_back(line.at(0), amount);
    }
    return instructions;
}



void follow_instruction(const Instruction& instruction, int& direction, std::pair<int, int>& pos) {
    switch (instruction.first) {
        case 'N':
            pos.second += instruction.second;
            break;
        case 'S':
            pos.second -= instruction.second;
            break;
        case 'E':
            pos.first += instruction.second;
            break;
        case 'W':
            pos.first -= instruction.second;
            break;
        case 'L':
            direction = (direction - instruction.second + 360) % 360;
            break;
        case 'R':
            direction = (direction + instruction.second) % 360;
            break;
        case 'F':
            switch (direction) {
                case 0:   pos.second += instruction.second; break;
                case 90:  pos.first += instruction.second; break;
                case 180: pos.second -= instruction.second; break;
                case 270: pos.first -= instruction.second; break;
                default: throw std::runtime_error("Unknown direction" + std::to_string(direction));
            }
            break;
        default: throw std::runtime_error("Unknown instruction" + std::to_string(instruction.first));
    }
}


void follow_instruction_2(const Instruction& instruction, std::pair<int, int>& pos, std::pair<int, int>& waypoint) {
    std::pair<int, int> tmp{waypoint};
    switch (instruction.first) {
        case 'N':
            waypoint.second += instruction.second;
            break;
        case 'S':
            waypoint.second -= instruction.second;
            break;
        case 'E':
            waypoint.first += instruction.second;
            break;
        case 'W':
            waypoint.first -= instruction.second;
            break;
        case 'L':
            switch (instruction.second) {
                case 0:   break;
                case 90:
                     waypoint.first = -tmp.second;
                     waypoint.second = tmp.first;
                     break;
                case 180: 
                     waypoint.first = -tmp.first;
                     waypoint.second = -tmp.second;
                     break;
                case 270:
                     waypoint.first = tmp.second;
                     waypoint.second = -tmp.first;
                     break;
                default: throw std::runtime_error("Unknown angle" + std::to_string(instruction.second));
            }
            break;
        case 'R':
            switch (instruction.second) {
                case 0:   break;
                case 90:
                     waypoint.first = tmp.second;
                     waypoint.second = - tmp.first;
                     break;
                case 180: 
                     waypoint.first = -tmp.first;
                     waypoint.second = -tmp.second;
                     break;
                case 270:
                     waypoint.first = -tmp.second;
                     waypoint.second = tmp.first;
                     break;
                default: throw std::runtime_error("Unknown angle" + std::to_string(instruction.second));
            }
            break;
        case 'F':
            pos.first += instruction.second * waypoint.first;
            pos.second += instruction.second * waypoint.second;
            break;
        default: throw std::runtime_error("Unknown instruction" + std::to_string(instruction.first));
    }
}


int part1(const std::vector<Instruction>& instructions) {
    int direction = 90;
    std::pair<int, int> pos{0, 0};

    for (const auto& instruction: instructions) {
        follow_instruction(instruction, direction, pos);
    }

    return std::abs(pos.first) + std::abs(pos.second);
}
int part2(const std::vector<Instruction>& instructions) {
    std::pair<int, int> pos{0, 0};
    std::pair<int, int> waypoint{10, 1};

    for (const auto& instruction: instructions) {
        follow_instruction_2(instruction, pos, waypoint);
    }

    return std::abs(pos.first) + std::abs(pos.second);
}


}}
