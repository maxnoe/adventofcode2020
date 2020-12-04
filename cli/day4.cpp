#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day4.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(4);
    auto passports = day4::parse_input(input);
    std::cout << "Solution 1: " << day4::part1(passports) << std::endl;
    std::cout << "Solution 2: " << day4::part2(passports) << std::endl;
    return 0;
}

