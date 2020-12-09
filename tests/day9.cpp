#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day9.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(35
20
15
25
47
40
62
55
65
95
102
117
150
182
127
219
299
277
309
576
)";


const std::vector<uint64_t> test_numbers = {
    35, 20, 15, 25, 47, 40, 62, 55, 65, 95, 102, 117,
    150, 182, 127, 219, 299, 277, 309, 576,
};


TEST(TestDay9, TestParse) {
    std::vector<uint64_t> numbers = day9::parse_input(test_input);
    ASSERT_EQ(test_numbers.size(), numbers.size());

    for(size_t idx = 0; idx < test_numbers.size(); idx++) {
        ASSERT_EQ(test_numbers.at(idx), numbers.at(idx));
    }
}


TEST(TestDay9, TestPart1) {
    ASSERT_EQ(127, day9::part1(test_numbers, 5));
}

TEST(TestDay9, TestPart2) {
    ASSERT_EQ(62, day9::part2(test_numbers, 127));
}

