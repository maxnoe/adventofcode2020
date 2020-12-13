#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day12.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(12);
    auto instructions = day12::parse_input(input);
    std::cout << "Solution 1: " << day12::part1(instructions) << std::endl;
    std::cout << "Solution 2: " << day12::part2(instructions) << std::endl;
    return 0;
}

