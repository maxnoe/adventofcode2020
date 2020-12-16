#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day14.h>
#include <ranges>

using namespace aocmaxnoe2020;

const std::string test_input = R"(mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X
mem[8] = 11
mem[7] = 101
mem[8] = 0
)";

const std::string test_input_2 = R"(mask = 000000000000000000000000000000X1001X
mem[42] = 100
mask = 00000000000000000000000000000000X0XX
mem[26] = 1)";

TEST(TestDay14, TestPart1) {
    auto instructions = day14::parse_input(test_input);
    ASSERT_EQ(165, day14::part1(instructions));
}

TEST(TestDay14, TestPart2) {
    auto instructions = day14::parse_input(test_input_2);
    ASSERT_EQ(208, day14::part2(instructions));
}

