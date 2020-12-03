#include "gtest/gtest.h"
#include <iostream>

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day3.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(..##.......
#...#...#..
.#....#..#.
..#.#...#.#
.#...##..#.
..#.##.....
.#.#.#....#
.#........#
#.##...#...
#...##....#
.#..#...#.#
)";

TEST(TestDay3, TestParse) {
    day3::trees_t trees = day3::parse_input(test_input);

    ASSERT_EQ(11, trees.size());

    for (const auto& row: trees) {
        ASSERT_EQ(11, row.size());
    }

    ASSERT_EQ(2, std::count(trees.at(0).begin(), trees.at(0).end(), true));
}

TEST(TestDay3, TestPart1) {
    day3::trees_t trees = day3::parse_input(test_input);
    ASSERT_EQ(7, day3::part1(trees));
}

TEST(TestDay3, TestPart2) {
    day3::trees_t trees = day3::parse_input(test_input);
    ASSERT_EQ(336, day3::part2(trees));
}
