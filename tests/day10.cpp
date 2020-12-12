#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day10.h>
#include <ranges>

using namespace aocmaxnoe2020;

std::vector<uint64_t> test_numbers_1 = {
    0, 16, 10, 15, 5, 1, 11, 7, 19, 6, 12, 4
};

std::vector<uint64_t> test_numbers_2 = {
    0, 28, 33, 18, 42, 31, 14, 46, 20, 48, 47, 24,
    23, 49, 45, 19, 38, 39, 11, 1, 32, 25, 35, 8,
    17, 7, 9, 4, 2, 34, 10, 3
};


TEST(TestDay10, TestPart1) {
    std::ranges::sort(test_numbers_1);
    std::ranges::sort(test_numbers_2);
    ASSERT_EQ(35, day10::part1(day10::diff(test_numbers_1)));
    ASSERT_EQ(220, day10::part1(day10::diff(test_numbers_2)));
}

TEST(TestDay10, TestPart2) {
    std::ranges::sort(test_numbers_1);
    std::ranges::sort(test_numbers_2);
    ASSERT_EQ(8, day10::part2(day10::diff(test_numbers_1)));
    ASSERT_EQ(19208, day10::part2(day10::diff(test_numbers_2)));
}

