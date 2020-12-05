#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(BFFFBBFRRR
FFFBBBFRRR
BBFFBBFRLL
)";

const std::vector<day5::boarding_pass_t> test_passes = {
    {70, 7},
    {14, 7},
    {102, 4},
};

const std::vector<int> ids {567, 119, 820};

TEST(TestDay5, TestParse) {
    auto boarding_passes = day5::parse_input(test_input);

    ASSERT_EQ(3, boarding_passes.size());

    for (size_t i = 0; i < test_passes.size(); i++) {
        ASSERT_EQ(test_passes.at(i).first, boarding_passes.at(i).first);
        ASSERT_EQ(test_passes.at(i).second, boarding_passes.at(i).second);
    }
}

TEST(TestDay5, TestID) {
    for (size_t i = 0; i < test_passes.size(); i++) {
        ASSERT_EQ(ids.at(i), day5::pass_id(test_passes.at(i)));
    }
}

TEST(TestDay5, TestPart1) {
    int max_id = day5::part1(test_passes);
    ASSERT_EQ(820, max_id);
}
