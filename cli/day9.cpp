#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day9.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(9);
    auto numbers = day9::parse_input(input);
    uint64_t part1 = day9::part1(numbers, 25);
    std::cout << "Solution 1: " << part1 << std::endl;
    std::cout << "Solution 2: " << day9::part2(numbers, part1) << std::endl;
    return 0;
}

