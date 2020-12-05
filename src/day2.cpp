#include <regex>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day2.h>


namespace aocmaxnoe2020 { namespace day2 {

const std::regex password_regex {"([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)"};

PasswordSpec parse_line(const std::string& line) {
    std::smatch match;
    std::regex_match(line, match, password_regex);

    if (match.empty()) {
        throw std::invalid_argument("Input does not match password spec");
    }

    return PasswordSpec{
        .min_count = std::stoi(match[1]),
        .max_count = std::stoi(match[2]),
        .character = match[3].str().at(0),
        .password = match[4]
    };
}


bool check_validity_part1(const PasswordSpec& pwd) {
    int count = std::count(pwd.password.begin(), pwd.password.end(), pwd.character);
    return (count >= pwd.min_count) && (count <= pwd.max_count);
}

bool check_validity_part2(const PasswordSpec& pwd) {
    bool found_at_pos1 = pwd.password.at(pwd.min_count - 1) == pwd.character;
    bool found_at_pos2 = pwd.password.at(pwd.max_count - 1) == pwd.character;
    return found_at_pos1 != found_at_pos2;
}


int count_valid_passwords(const std::vector<PasswordSpec>& passwords, checker_t checker) {
    return std::count_if(passwords.begin(), passwords.end(), checker);
}

int part1(const std::vector<PasswordSpec>& passwords) {
    return count_valid_passwords(passwords, check_validity_part1);
}

int part2(const std::vector<PasswordSpec>& passwords) {
    return count_valid_passwords(passwords, check_validity_part2);
}

std::ostream& operator<<(std::ostream& os, const PasswordSpec& pwd)
{
    os << "PasswordSpec(" << std::to_string(pwd.min_count)
        << ", " << std::to_string(pwd.max_count)
        << ", " << pwd.character
        << ", " << pwd.password
        << ")";
    return os;
}


std::vector<PasswordSpec> parse_input(const std::string& input) {
    auto lines = split_lines(input);
    std::vector<PasswordSpec> passwords;
    passwords.reserve(lines.size());

    for (auto line: lines) {
        passwords.push_back(parse_line(std::string(line)));
    }

    return passwords;
}

bool operator==(const PasswordSpec& lhs, const PasswordSpec& rhs) {
    return (lhs.min_count == rhs.min_count)
        && (lhs.max_count == rhs.max_count)
        && (lhs.character == rhs.character)
        && (lhs.password == rhs.password)
        ;
}

}}

