#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day12.h>
#include <ranges>

using namespace aocmaxnoe2020;

const std::string test_input = R"(F10
N3
F7
R90
F11
)";

const std::vector<day12::Instruction> test_instructions = {
    {'F', 10},
    {'N', 3},
    {'F', 7},
    {'R', 90},
    {'F', 11},
};


TEST(TestDay12, TestParse) {
    auto instructions = day12::parse_input(test_input);
    ASSERT_EQ(test_instructions.size(), instructions.size());
    for (size_t i = 0; i < test_instructions.size(); i++) {
        ASSERT_EQ(test_instructions.at(i), instructions.at(i));
    }
}

TEST(TestDay12, TestFollow) {
    int direction = 90;
    std::pair<int, int> pos{0, 0};

    day12::follow_instruction(test_instructions.at(0), direction, pos);
    ASSERT_EQ(direction, 90);
    ASSERT_EQ(pos.first, 10);
    ASSERT_EQ(pos.second, 0);

    day12::follow_instruction(test_instructions.at(1), direction, pos);
    ASSERT_EQ(direction, 90);
    ASSERT_EQ(pos.first, 10);
    ASSERT_EQ(pos.second, 3);

    day12::follow_instruction(test_instructions.at(2), direction, pos);
    ASSERT_EQ(direction, 90);
    ASSERT_EQ(pos.first, 17);
    ASSERT_EQ(pos.second, 3);

    day12::follow_instruction(test_instructions.at(3), direction, pos);
    ASSERT_EQ(direction, 180);
    ASSERT_EQ(pos.first, 17);
    ASSERT_EQ(pos.second, 3);

    day12::follow_instruction(test_instructions.at(4), direction, pos);
    ASSERT_EQ(direction, 180);
    ASSERT_EQ(pos.first, 17);
    ASSERT_EQ(pos.second, -8);
}

TEST(TestDay12, TestPart1) {
    ASSERT_EQ(25, day12::part1(test_instructions));
}

TEST(TestDay12, TestPart2) {
    ASSERT_EQ(286, day12::part2(test_instructions));
}

