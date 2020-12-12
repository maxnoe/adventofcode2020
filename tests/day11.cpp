#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day11.h>
#include <ranges>

using namespace aocmaxnoe2020;

const std::string test_input = R"(L.LL.LL.LL
LLLLLLL.LL
L.L.L..L..
LLLL.LL.LL
L.LL.LL.LL
L.LLLLL.LL
..L.L.....
LLLLLLLLLL
L.LLLLLL.L
L.LLLLL.LL
)";

TEST(TestDay11, TestPart1) {
    auto lines = split_lines(test_input);
    ASSERT_EQ(37, day11::part1(lines));
}

TEST(TestDay11, TestPart2) {
    auto lines = split_lines(test_input);
    ASSERT_EQ(26, day11::part2(lines));
}

