#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day13.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(13);
    auto [min_time, busses] = day13::parse_input(input);
    std::cout << "Solution 1: " << day13::part1(min_time, busses) << std::endl;
    std::cout << "Solution 2: " << day13::part2(busses) << std::endl;
    return 0;
}

