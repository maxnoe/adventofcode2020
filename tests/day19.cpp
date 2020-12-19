#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day19.h>
#include <ranges>
#include <numeric>

using namespace aocmaxnoe2020;
using namespace testing;

const std::string test_input = R"(0: 4 1 5
1: 2 3 | 3 2
2: 4 4 | 5 5
3: 4 5 | 5 4
4: "a"
5: "b"

ababbb
bababa
abbbab
aaabbb
aaaabbb
)";


day19::rules_t test_rules = {
    {0, "(a)(((a)(a)|(b)(b))((a)(b)|(b)(a))|((a)(b)|(b)(a))((a)(a)|(b)(b)))(b)"},
    {1, "((a)(a)|(b)(b))((a)(b)|(b)(a))|((a)(b)|(b)(a))((a)(a)|(b)(b))"},
    {2, "(a)(a)|(b)(b)"},
    {3, "(a)(b)|(b)(a)"},
    {4, "a"},
    {5, "b"},
};


TEST(TestDay19, TestParse) {
    auto input = day19::parse_input(test_input);
    for(auto [id, rule]: test_rules) {
        std::cout << id << std::endl;
        ASSERT_TRUE(input.rules.contains(id));
        ASSERT_EQ(input.rules.at(id), test_rules.at(id));
    }
}

TEST(TestDay19, TestPart1) {
    auto input = day19::parse_input(test_input);
    ASSERT_EQ(2, day19::part1(input));
}

TEST(TestDay14, TestPart2) {
}
