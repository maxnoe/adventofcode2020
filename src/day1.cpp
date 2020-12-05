#include <unordered_set>
#include <unordered_map>
#include <string>
#include <stdexcept>

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day1.h>

namespace aocmaxnoe2020 { namespace day1 {

std::unordered_set<int> parse_input(const std::string& input) {
    auto lines = split_lines(input);
    std::unordered_set<int> numbers;

    for (std::string_view line: lines) {
        numbers.insert(std::stoi(std::string(line)));
    }

    return numbers;
}

int part1(const std::unordered_set<int>& numbers) {
    for (auto number: numbers) {
        if (numbers.find(TARGET - number) != numbers.end()) {
            return number * (TARGET - number);
        }
    }

    throw std::runtime_error("Did not find matching number");
}

int part2(const std::unordered_set<int>& numbers) {

    for (auto val1: numbers) {
        for (auto val2: numbers) {
            int val3 = TARGET - val1 - val2;
            if (numbers.find(val3) != numbers.end()) {
                return val1 * val2 * val3;
            }
        }
    }

    throw std::runtime_error("Did not find matching number");
}

}}
