#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day11.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(11);
    auto lines = split_lines(input);
    std::cout << "Solution 1: " << day11::part1(lines) << std::endl;
    std::cout << "Solution 2: " << day11::part2(lines) << std::endl;
    return 0;
}

