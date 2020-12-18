#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day18.h>
#include <ranges>
#include <numeric>

using namespace aocmaxnoe2020;
using namespace testing;

const std::string test_input = R"(1 + 2 * 3 + 4 * 5 + 6
2 * 3 + (4 * 5)
5 + (8 * 3 + 9 + 3 * 4 * 3)
5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))
((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2
)";

const std::vector<int> test_results {71, 26, 437, 12240, 13632};

TEST(TestDay18, TestParse) {
    auto expressions = day18::parse_input(test_input);
    ASSERT_EQ(test_results.size(), expressions.size());

    for (size_t i = 0; i < test_results.size(); i++) {
        std::cout << expressions.at(i)->toString() << std::endl;
        ASSERT_EQ(test_results.at(i), expressions.at(i)->evaluate());
    }
};

TEST(TestDay18, TestPart1) {
    auto expressions = day18::parse_input(test_input);

    uint64_t sum = std::accumulate(test_results.begin(), test_results.end(), 0ull);
    ASSERT_EQ(sum, day18::part1(expressions));

}

TEST(TestDay14, TestPart2) {
}
