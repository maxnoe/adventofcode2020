#include "gtest/gtest.h"

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day16.h>
#include <ranges>

using namespace aocmaxnoe2020;
using namespace testing;

const std::string test_input = R"(class: 1-3 or 5-7
row: 6-11 or 33-44
seat: 13-40 or 45-50

your ticket:
7,1,14

nearby tickets:
7,3,47
40,4,50
55,2,20
38,6,12
)";


const day16::Input test_parsed_input {
    .specifications = {
        {"class", {1, 3, 5, 7}},
        {"row", {6, 11, 33, 44}},
        {"seat", {13, 40, 45, 50}}
    },
    .my_ticket = {7, 1, 14},
    .nearby_tickets = {
        {7, 3, 47}, {40, 4, 50}, {55, 2, 20}, {38, 6, 12},
    },
};

TEST(TestDay16, TestParse) {
    auto parsed_input = day16::parse_input(test_input);

    for (size_t i = 0; i < test_parsed_input.my_ticket.size(); i++) {
        ASSERT_EQ(test_parsed_input.my_ticket.at(i), parsed_input.my_ticket.at(i));
    }
    
    for (const auto& [k, v]: test_parsed_input.specifications) {
        ASSERT_EQ(v.min1, parsed_input.specifications[k].min1);
        ASSERT_EQ(v.min2, parsed_input.specifications[k].min2);
        ASSERT_EQ(v.max1, parsed_input.specifications[k].max1);
        ASSERT_EQ(v.max2, parsed_input.specifications[k].max2);
    }

    for (size_t i = 0; i < test_parsed_input.nearby_tickets.size(); i++) {
        size_t size = test_parsed_input.nearby_tickets.at(i).size();
        ASSERT_EQ(size, parsed_input.nearby_tickets.at(i).size());

        for (size_t j = 0; j < size; j++) {
            ASSERT_EQ(test_parsed_input.nearby_tickets.at(i).at(j), parsed_input.nearby_tickets.at(i).at(j));
        }
    }
};

TEST(TestDay16, TestPart1) {
    ASSERT_EQ(71, day16::part1(test_parsed_input));
}

TEST(TestDay14, TestPart2) {
}
