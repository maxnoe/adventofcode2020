#include <string>
#include <iostream>
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>


using namespace aocmaxnoe2020;


int main() {
    std::string input = get_input(5);
    auto [max_id, free_seat] = day5::day5(input);
    std::cout << "Solution 1: " << max_id << std::endl;
    std::cout << "Solution 2: " << free_seat << std::endl;
    return 0;
}

