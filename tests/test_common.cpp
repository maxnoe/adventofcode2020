#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>

using namespace aocmaxnoe2020;


std::vector<std::string> expected = {"foo", "bar", "baz"};

TEST(TestCommon, TestSplitSingle) {
    auto result = split("foo|bar|baz", "|");
    ASSERT_EQ(expected.size(), result.size());
    for (size_t idx; idx < expected.size(); idx++){ 
        ASSERT_EQ(expected.at(idx), result.at(idx));
    }
}

TEST(TestCommon, TestSplitMultiple) {
    auto result = split("foo, bar, baz", ", ");
    ASSERT_EQ(expected.size(), result.size());
    for (size_t idx; idx < expected.size(); idx++){ 
        ASSERT_EQ(expected.at(idx), result.at(idx));
    }
}

TEST(TestCommon, TestSplitLines) {
    auto result = split_lines("foo\nbar\nbaz\n");
    ASSERT_EQ(expected.size(), result.size());
    for (size_t idx; idx < expected.size(); idx++){ 
        ASSERT_EQ(expected.at(idx), result.at(idx));
    }
}
