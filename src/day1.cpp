#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <aocmaxnoe2020.h>
#include <sstream>
#include <vector>



namespace aocmaxnoe2020 {
namespace day1 {

const int TARGET = 2020;



int part1(const std::unordered_set<int>& numbers){
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


int main() {
    std::string input = aocmaxnoe2020::get_input(1);

    auto lines = aocmaxnoe2020::split_lines(input);

    std::unordered_set<int> numbers;
    for (auto line: lines) {
        numbers.insert(std::stoi(line));
    }

    std::cout << "Solution 1:" << aocmaxnoe2020::day1::part1(numbers) << std::endl;
    std::cout << "Solution 1:" << aocmaxnoe2020::day1::part2(numbers) << std::endl;

    return 0;
}

