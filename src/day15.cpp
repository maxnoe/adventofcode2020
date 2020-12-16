#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day15.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <limits>

namespace aocmaxnoe2020 { namespace day15 {


const uint64_t NA = std::numeric_limits<uint64_t>::max();


std::vector<uint64_t> parse_input(std::string_view input) {
    std::vector<uint64_t> numbers;
    for (auto s: split(input, ",")) {
        numbers.push_back(std::stoi(std::string{s}));
    }
    return numbers;
}

uint64_t counting_game(const std::vector<uint64_t>& numbers, size_t max) {
    std::unordered_map<uint64_t, std::pair<uint64_t, uint64_t>> memory;

    uint64_t last_number = 0;

    for (size_t i = 0; i < max; i++) {

        // starting numbers
        if (i < numbers.size()) {
            last_number = numbers.at(i);
        // last number was spoken for the first time
        } else if (memory.contains(last_number) && memory[last_number].first == NA) {
            last_number = 0;
        } else {
            last_number = memory[last_number].second - memory[last_number].first;
        }

        if (!memory.contains(last_number)) {
            memory[last_number] = {NA, i};
        } else {
            memory[last_number].first = memory[last_number].second;
            memory[last_number].second = i;
        }
    }

    return last_number;
}

uint64_t part1(const std::vector<uint64_t>& numbers) {
    return counting_game(numbers, 2020);
}
uint64_t part2(const std::vector<uint64_t>& numbers) {
    return counting_game(numbers, 30000000);
}


}}
