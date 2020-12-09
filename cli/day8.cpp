#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day8.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(8);
    auto program = day8::parse_input(input);
    std::cout << "Solution 1: " << day8::part1(program) << std::endl;
    std::cout << "Solution 2: " << day8::part2(program) << std::endl;
    return 0;
}

