#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day7.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(7);
    auto rules = day7::parse_input(input);
    std::cout << "Solution 1: " << day7::part1(rules) << std::endl;
    std::cout << "Solution 2: " << day7::part2(rules) << std::endl;
    return 0;
}

