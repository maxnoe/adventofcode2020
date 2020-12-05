#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(5);
    auto boarding_passes = day5::parse_input(input);
    std::cout << "Solution 1: " << day5::part1(boarding_passes) << std::endl;
    std::cout << "Solution 2: " << day5::part2(boarding_passes) << std::endl;
    return 0;
}

