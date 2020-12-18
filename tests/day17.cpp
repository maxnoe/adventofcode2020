#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day17.h>
#include <ranges>

using namespace aocmaxnoe2020;
using namespace testing;

const std::string test_input = R"(.#.
..#
###
)";

const day17::Point3D::Set test_state {
    {1, 0, 0},
    {2, -1, 0},
    {0, -2, 0},
    {1, -2, 0},
    {2, -2, 0},
};

TEST(TestDay17, TestParse) {

    auto state = day17::parse_input(test_input);
    ASSERT_EQ(test_state.size(), state.size());

    for (const auto& p: test_state) {
        ASSERT_TRUE(state.contains(p));
    }
};

TEST(TestDay17, TestPart1) {
    ASSERT_EQ(112, day17::part1(test_state));
}

TEST(TestDay14, TestPart2) {
    ASSERT_EQ(848, day17::part2(test_state));
}
