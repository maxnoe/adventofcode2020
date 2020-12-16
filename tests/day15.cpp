#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day15.h>
#include <ranges>

using namespace aocmaxnoe2020;


std::vector<std::vector<uint64_t>> test_cases {
    {1,3,2},
    {2,1,3},
    {1,2,3},
    {2,3,1},
    {3,2,1},
    {3,1,2},
};

std::vector<uint64_t> solutions_1 = {1, 10, 27, 78, 438, 1836};
std::vector<uint64_t> solutions_2 = {2578, 3544142, 261214, 6895259, 18, 362};


TEST(TestDay15, TestPart1) {
    for (size_t i = 0; i < test_cases.size(); i++) {
        ASSERT_EQ(solutions_1.at(i), day15::part1(test_cases.at(i)));
    }
}

TEST(TestDay14, TestPart2) {
    for (size_t i = 0; i < test_cases.size(); i++) {
        ASSERT_EQ(solutions_2.at(i), day15::part2(test_cases.at(i)));
    }
}
