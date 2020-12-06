#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day6.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(abc

a
b
c

ab
ac

a
a
a
a

b
)";

const std::vector<day6::group_t> test_groups = {
    {"abc"},
    {"a", "b", "c"},
    {"ab", "ac"},
    {"a", "a", "a", "a"},
    {"b"}
};


TEST(TestDay6, TestParse) {
    auto groups = day6::parse_input(test_input);
    ASSERT_EQ(test_groups.size(), groups.size());

    for (size_t i=0; i < test_groups.size(); i++) {
        ASSERT_EQ(test_groups.at(i), groups.at(i));
    }
}


TEST(TestDay6, TestPart1) {
    ASSERT_EQ(11, day6::part1(test_groups));
}

TEST(TestDay6, TestPart2) {
    ASSERT_EQ(6, day6::part2(test_groups));
}

