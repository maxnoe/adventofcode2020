#include <string>
#include <iostream>
#include <unordered_set>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day1.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(1);
    auto numbers = day1::parse_input(input);
    std::cout << "Solution 1:" << day1::part1(numbers) << std::endl;
    std::cout << "Solution 2:" << day1::part2(numbers) << std::endl;
    return 0;
}

