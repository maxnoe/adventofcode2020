
#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day4.h>
#include <iostream>
#include <string_view>
#include <regex>
#include <ranges>
#include <algorithm>


namespace aocmaxnoe2020 { namespace day4 {




passport_t parse_passport(const std::string& token) {

    passport_t passport;
    std::regex re{"([a-z]+):([a-z0-9#]+)"};
    std::smatch match;

    auto start = token.cbegin();
    while (std::regex_search(start, token.cend(), match, re)) {
        passport[match[1]] = match[2];
        start = match.suffix().first;
    }
    return passport;
}


passports_t parse_input(const std::string& input) {
    auto tokens = split(input, "\n\n");
    passports_t passports;
    passports.reserve(tokens.size());

    for (const std::string& token: tokens) {
        passports.push_back(parse_passport(token));
    }

    return passports;
}


bool has_all_required(const passport_t& passport) {
    return std::ranges::all_of(
        REQUIRED_KEYS_1.cbegin(),
        REQUIRED_KEYS_1.cend(),
        [&passport](const std::string& key){return passport.contains(key);}
    );
}

bool is_valid(const passport_t& passport) {
    if (!has_all_required(passport)) return false;

    int byr = std::stoi(passport.at("byr"));
    if (byr < 1920 || byr > 2002) return false;

    int iyr = std::stoi(passport.at("iyr"));
    if (iyr < 2010 || iyr > 2020) return false;

    int eyr = std::stoi(passport.at("eyr"));
    if (eyr < 2020 || eyr > 2030) return false;

    const std::string& hcl = passport.at("hcl");
    std::regex hcl_re{"#[0-9a-f]{6}"};
    if (!std::regex_match(hcl, hcl_re)) return false;

    std::unordered_set<std::string> allowed_colors {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    if (allowed_colors.count(passport.at("ecl")) == 0) return false;

    const std::string& pid = passport.at("pid");
    std::regex pid_re{"[0-9]{9}"};
    if (!std::regex_match(pid, pid_re)) return false;

    const std::string& height = passport.at("hgt");
    std::regex height_re {"([0-9]+)(in|cm)"};
    std::smatch match;
    if (!std::regex_match(height, match, height_re)) return false;

    int height_val = std::stoi(match[1]);
    if (match[2] == "cm") {
        if (height_val < 150 || height_val > 193) return false;
    } else {
        if (height_val < 59 || height_val > 76) return false;
    }

    return true;
}


int part1(const passports_t& passports) {
    return std::count_if(passports.cbegin(), passports.cend(), &has_all_required);
}

long part2(const passports_t& passports) {
    return std::count_if(passports.begin(), passports.end(), &is_valid);
}

}}

