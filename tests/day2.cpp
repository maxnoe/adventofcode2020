#include "gtest/gtest.h"
#include <iostream>

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day2.h>

using namespace aocmaxnoe2020;

const std::string test_input = R"(1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc
)";

const std::vector<day2::PasswordSpec> test_passwords{
    { .min_count=1, .max_count=3, .character='a', .password="abcde"},
    { .min_count=1, .max_count=3, .character='b', .password="cdefg"},
    { .min_count=2, .max_count=9, .character='c', .password="ccccccccc"},
};

TEST(TestDay2, TestParse) {
    auto passwords = day2::parse_input(test_input);

    ASSERT_EQ(test_passwords.size(), passwords.size());
    for (size_t idx = 0; idx < test_passwords.size(); idx++) {
        ASSERT_EQ(test_passwords.at(idx), passwords.at(idx));
    }
}

TEST(TestDay2, TestPart1) {
    ASSERT_TRUE(check_validity_part1(test_passwords.at(0)));
    ASSERT_FALSE(check_validity_part1(test_passwords.at(1)));
    ASSERT_TRUE(check_validity_part1(test_passwords.at(2)));

    ASSERT_EQ(day2::part1(test_passwords), 2);
}

TEST(TestDay2, TestPart2) {
    ASSERT_TRUE(check_validity_part2(test_passwords.at(0)));
    ASSERT_FALSE(check_validity_part2(test_passwords.at(1)));
    ASSERT_FALSE(check_validity_part2(test_passwords.at(2)));

    ASSERT_EQ(day2::part2(test_passwords), 1);
}
