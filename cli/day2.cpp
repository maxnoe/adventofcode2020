#include <string>
#include <iostream>
#include <unordered_set>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day2.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(2);
    auto passwords = day2::parse_input(input);
    std::cout << "Solution 1: " << day2::part1(passwords) << std::endl;
    std::cout << "Solution 2: " << day2::part2(passwords) << std::endl;
    return 0;
}

