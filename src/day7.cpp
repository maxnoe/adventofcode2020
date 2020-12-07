#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day7.h>
#include <unordered_map>
#include <regex>
#include <ranges>

namespace aocmaxnoe2020 { namespace day7 {

std::pair<std::string, contents_t> parse_bag_rule(const std::string& line) {

    std::smatch match;
    std::regex re{R"(([a-z ]+?) bags contain (.*).)"};

    std::regex_match(line, match, re);

    contents_t contents;
    auto ret = std::make_pair(match[1], contents);

    std::string contains = match[2];
    if (contains.ends_with("no other bags.")) {
        return ret;
    }

    std::regex contains_re{R"((\d+) (\w+ \w+) bags?)"};
    auto start = contains.cbegin();
    while (std::regex_search(start, contains.cend(), match, contains_re)) {
        ret.second[match[2]] = std::stoi(match[1]); 
        start = match.suffix().first;
    }

    return ret;
}

rules_t parse_input(std::string_view input){
    auto lines = split_lines(input);

    rules_t rules;
    rules.reserve(lines.size());
    for (std::string_view line: lines) {
        // regex does not support string_view yet
        auto [color, contents] = parse_bag_rule(std::string{line});
        rules[color] = contents;
    }

    return rules;
}


bool can_contain(const std::string& color, const std::string& target, const rules_t& rules) {

    if (rules.at(color).contains(target)) {
        return true;
    }

    for (const auto& key: rules.at(color) | std::views::keys) {
        if (can_contain(key, target, rules)) {
            return true;
        }
    }

    return false;
}


size_t count_bags_inside(const std::string& color, const rules_t rules) {
    if (rules.at(color).size() == 0) {
        return 0;
    }

    size_t bags = 0;
    for (const auto& [key, count]: rules.at(color)) {
        bags += count * (1 + count_bags_inside(key, rules));
    }

    return bags;
}


int part1(const rules_t& rules) {
    int n_total = 0;
    for (const auto& color: rules | std::views::keys) {
        if (can_contain(color, "shiny gold", rules)) {
            n_total++;
        }
    }
    return n_total;
}

int part2(const rules_t& rules) {
    return count_bags_inside("shiny gold", rules);
}

}}

