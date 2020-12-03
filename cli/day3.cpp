#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day3.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(3);
    auto trees = day3::parse_input(input);
    std::cout << "Solution 1: " << day3::part1(trees) << std::endl;
    std::cout << "Solution 2: " << day3::part2(trees) << std::endl;
    return 0;
}

