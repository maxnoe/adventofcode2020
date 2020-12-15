#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day14.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(14);
    auto instructions = day14::parse_input(input);
    std::cout << "Solution 1: " << day14::part1(instructions) << std::endl;
    std::cout << "Solution 2: " << day14::part2(instructions) << std::endl;
    return 0;
}

