#include <regex>
#include <string>
#include <stdexcept>
#include <iostream>

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day2.h>


namespace aocmaxnoe2020 { namespace day2 {

const std::regex password_regex {"([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)"};

PasswordSpec::PasswordSpec(const std::string& password_spec) {
    std::smatch match;
    std::regex_match(password_spec, match, password_regex);

    if (match.empty()) {
        throw std::invalid_argument("Input does not match password spec");
    }

    min_count = std::stoi(match[1]);
    max_count = std::stoi(match[2]);
    character = match[3].str().at(0);
    password = match[4];
}

bool PasswordSpec::is_valid_part1() const {
    int count = std::count(password.begin(), password.end(), character);
    return (count >= min_count) && (count <= max_count);
}

bool PasswordSpec::is_valid_part2() const {
    bool found_at_pos1 = password.at(min_count - 1) == character;
    bool found_at_pos2 = password.at(max_count - 1) == character;
    return found_at_pos1 != found_at_pos2;
}

int part1(const std::vector<PasswordSpec>& passwords) {
    int valid = 0;
    for (auto password: passwords) {
        if (password.is_valid_part1()) {
            valid++;
        }
    }
    return valid;
}

int part2(const std::vector<PasswordSpec>& passwords) {
    int valid = 0;
    for (auto password: passwords) {
        if (password.is_valid_part2()) {
            valid++;
        }
    }
    return valid;
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
        passwords.emplace_back(line);
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

