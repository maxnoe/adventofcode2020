#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day13.h>
#include <ranges>

using namespace aocmaxnoe2020;

const std::string test_input = R"(939
7,13,x,x,59,x,31,19
)";

const int test_min_time = 939;
const day13::busses_t test_busses = {7,13,-1,-1,59,-1,31,19};


TEST(TestDay13, TestParse) {
    auto [min_time, busses] = day13::parse_input(test_input);
    ASSERT_EQ(test_min_time, min_time);

    ASSERT_EQ(test_busses.size(), busses.size());
    for (size_t i = 0; i < test_busses.size(); i++) {
        ASSERT_EQ(test_busses.at(i), busses.at(i));
    }
}

TEST(TestDay13, TestPart1) {
    ASSERT_EQ(295, day13::part1(test_min_time, test_busses));
}

TEST(TestDay13, TestPart2) {
    int x = -1;
    ASSERT_EQ(1068781, day13::part2(test_busses));
    ASSERT_EQ(3417, day13::part2({17,x,13,19}));
    ASSERT_EQ(754018, day13::part2({67,7,59,61}));
    ASSERT_EQ(779210, day13::part2({67,x,7,59,61}));
    ASSERT_EQ(1261476, day13::part2({67,7,x,59,61}));
    ASSERT_EQ(1202161486, day13::part2({1789,37,47,1889}));
}

