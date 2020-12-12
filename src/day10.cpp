#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day10.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

namespace aocmaxnoe2020 { namespace day10 {


std::vector<uint64_t> diff(const std::vector<uint64_t>& numbers) {
    std::vector<uint64_t> diffs;
    diffs.reserve(numbers.size() - 1);
    for (size_t i = 1; i < numbers.size(); i++) {
        diffs.push_back(numbers.at(i) - numbers.at(i - 1));
    }
    return diffs;
}

std::vector<uint64_t> parse_input(std::string_view input) {
    auto lines = split_lines(input);
    std::vector<uint64_t> numbers;
    numbers.reserve(lines.size() + 1);
    numbers.push_back(0);

    for (std::string_view line: lines) {
        numbers.push_back(std::stoll(std::string{line}));
    }

    std::ranges::sort(numbers);

    return diff(numbers);
}

template <typename T>
std::unordered_map<T, size_t> count(const std::vector<T> values) {
    std::unordered_map<T, size_t> counter;
    for (T v: values) {
        if (!counter.contains(v)) counter[v] = 0;
        counter[v]++;
    }
    return counter;
}


uint64_t part1(const std::vector<uint64_t>& diffs) {

    auto counter = count(diffs);
    if (counter.contains(3) && counter.contains(1)) {
        // one 3 difference for the thing itself.
        counter[3]++;
        return counter[3] * counter[1];
    }

    return 0;
}

uint64_t possibilities(uint64_t n_consecutive) {
    switch (n_consecutive) {
        case 4: return 7;
        case 3: return 4;
        case 2: return 2;
        case 1: return 1;
        case 0: return 1;
        default: return 0;
    }
}

uint64_t part2(const std::vector<uint64_t>& diffs) {
    int n_consecutive = 0;
    uint64_t n = 1;

    for (auto diff: diffs) {
        if (diff == 1) {
            n_consecutive++;
        } else {
            n *= possibilities(n_consecutive);
            n_consecutive = 0;
        }
    }

    n *= possibilities(n_consecutive);
    return n;
}

}}
