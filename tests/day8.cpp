#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day8.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6
)";


const std::vector<day8::Instruction> test_program = {
    {"nop", 0},
    {"acc", 1},
    {"jmp", 4},
    {"acc", 3},
    {"jmp", -3},
    {"acc", -99},
    {"acc", 1},
    {"jmp", -4},
    {"acc", 6},
};


TEST(TestDay8, TestParse) {
    auto program = day8::parse_input(test_input);
    ASSERT_EQ(program.size(), test_program.size());
    for (size_t idx=0; idx < test_program.size(); idx++) {
        ASSERT_EQ(program.at(idx), test_program.at(idx));
    }
}


TEST(TestDay8, TestPart1) {
    ASSERT_EQ(5, day8::part1(test_program));
}

TEST(TestDay8, TestPart2) {
    ASSERT_EQ(8, day8::part2(test_program));
}
