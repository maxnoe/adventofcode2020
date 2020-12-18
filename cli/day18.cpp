#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day18.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(18);
    auto parsed_input = day18::parse_input(input);

    auto sol1 = day18::part1(parsed_input);
    std::cout << "Solution 1: " << sol1  << std::endl;

    auto sol2 = day18::part2(parsed_input);
    std::cout << "Solution 2: " << sol2 << std::endl;
    return 0;
}

