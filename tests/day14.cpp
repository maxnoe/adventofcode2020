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

TEST(TestDay14, TestPart1) {
    auto program = day14::parse_input(test_input);
    ASSERT_EQ(165, day14::part1(program));

}

TEST(TestDay14, TestPart2) {
}

