#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day10.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(10);
    auto numbers = day10::parse_input(input);
    uint64_t part1 = day10::part1(numbers);
    std::cout << "Solution 1: " << part1 << std::endl;
    std::cout << "Solution 2: " << day10::part2(numbers) << std::endl;
    return 0;
}

