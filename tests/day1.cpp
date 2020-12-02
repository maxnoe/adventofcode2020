#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day1.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(1721
979
366
299
675
1456
)";

const std::unordered_set<int> test_numbers{1721, 979, 366, 299, 675, 1456};

TEST(TestDay1, TestParse) {
    auto numbers = day1::parse_input(test_input);
    ASSERT_EQ(numbers, test_numbers);
}

TEST(TestDay1, TestPart1) {
    int solution1 = day1::part1(test_numbers);
    ASSERT_EQ(solution1, 514579);
}

TEST(TestDay1, TestPart2) {
    int solution2 = day1::part2(test_numbers);
    ASSERT_EQ(solution2, 241861950);
}
