#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day6.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(6);
    auto groups = day6::parse_input(input);
    std::cout << "Solution 1: " << day6::part1(groups) << std::endl;
    std::cout << "Solution 2: " << day6::part2(groups) << std::endl;
    return 0;
}

