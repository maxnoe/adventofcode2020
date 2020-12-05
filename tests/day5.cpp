#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day5.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(BFFFBBFRRR
FFFBBBFRRR
BBFFBBFRLL
)";

const std::vector<std::string_view> test_inputs = split_lines(test_input);

const std::vector<day5::boarding_pass_t> test_passes = {
    {70, 7},
    {14, 7},
    {102, 4},
};

const std::vector<int> ids {567, 119, 820};

TEST(TestDay5, TestParse) {
    for (size_t i = 0; i < test_passes.size(); i++) {
        auto [row, col] = day5::parse_pass(test_inputs.at(i));
        ASSERT_EQ(test_passes.at(i).first, row);
        ASSERT_EQ(test_passes.at(i).second, col);
    }
}

TEST(TestDay5, TestID) {
    for (size_t i = 0; i < test_passes.size(); i++) {
        ASSERT_EQ(ids.at(i), day5::pass_id(test_passes.at(i)));
    }
}

TEST(TestDay5, TestDay5) {
    auto [max_id, free_seat] = day5::day5(test_input);
    ASSERT_EQ(820, max_id);
}
