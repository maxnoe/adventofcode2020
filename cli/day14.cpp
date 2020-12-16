#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day14.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(14);
    auto instructions = day14::parse_input(input);

    uint64_t sol1 = day14::part1(instructions);
    std::cout << "Solution 1: " << sol1  << std::endl;

    uint64_t sol2 = day14::part2(instructions);
    std::cout << "Solution 2: " << sol2 << std::endl;
    return 0;
}

