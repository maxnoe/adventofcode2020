#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day9.h>
#include <vector>
#include <algorithm>
#include <iostream>

namespace aocmaxnoe2020 { namespace day9 {

std::vector<uint64_t> parse_input(std::string_view input) {
    auto lines = split_lines(input);
    std::vector<uint64_t> numbers;
    numbers.reserve(lines.size());
    for (std::string_view line: lines) {
        numbers.push_back(std::stoll(std::string{line}));
    }

    return numbers;
}

int part1(const std::vector<uint64_t>& numbers, size_t buffer_size) {
    for (size_t index = buffer_size; index < numbers.size(); index++) {

        uint64_t number = numbers.at(index);

        auto start = numbers.cbegin() + index - buffer_size;
        auto end = numbers.cbegin() + index;

        bool valid = false;

        for (auto it = start; it < end; it++) {
            uint64_t other = *it;
            uint64_t target = number - other;

            if (other != target && std::find(start, end, target) != end) {
                valid  = true;
                break;
            }
        }
        if (!valid) {
            return number;
        }
    }

    return 0;
}

int part2(const std::vector<uint64_t>& numbers, uint64_t target) {
    for (auto start = numbers.cbegin(); start < numbers.cend(); start++) {
        uint64_t sum = 0;

        for (auto it = start; it < numbers.cend(); it++) {
            if (*it == target) break; 

            sum += *it;
            
            // found, return sum of min and max number
            if (sum == target) {
                auto [min, max] = std::minmax_element(start, it);
                return (*min) + (*max);
            }

            if (sum > target) break;
        }
        
    }
    return 0;
}

}}

