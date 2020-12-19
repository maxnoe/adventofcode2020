#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day19.h>
#include <iostream>
#include <regex>
#include <string>
#include <ranges>
#include <algorithm>


namespace aocmaxnoe2020 { namespace day19 {


std::string resolve_rule(size_t id, const rules_t& rules, rules_t& resolved_rules) {
    if (resolved_rules.contains(id)) {
        return resolved_rules.at(id);
    }

    std::string rule = rules.at(id);

    rule.erase(std::ranges::remove(rule, '"').begin(), rule.end());

    std::regex id_re{R"((\d+))"};
    std::smatch match;

    while (std::regex_search(rule.cbegin(), rule.cend(), match, id_re)) {
        size_t other_id = std::stoul(match[1]);
        std::string replacement = resolve_rule(other_id, rules, resolved_rules);
        rule.replace(match.position(1), match.length(1), "(" + replacement + ")");
    }

    rule.erase(std::ranges::remove(rule, ' ').begin(), rule.end());
    resolved_rules[id] = rule;
    return rule;
}


Input parse_input(std::string_view input) {

    auto parts = split(input, "\n\n");
    if (parts.size() != 2) throw std::runtime_error("Wrong number of parts");

    auto lines = split_lines(parts.at(0));

    rules_t rules;
    rules.reserve(lines.size());
    rules_t resolved_rules;
    resolved_rules.reserve(lines.size());

    for (auto line: lines) {
        auto colon = line.find(": ");
        if (colon == std::string::npos) throw std::runtime_error("Line does not have a colon: " + std::string{line});

        size_t id = std::stoul(std::string{line.substr(0, colon)});

        rules[id] = line.substr(colon + 2, line.size() - colon - 2);
    }

    for (size_t id : std::views::keys(rules)) {
        resolve_rule(id, rules, resolved_rules);
    }

    return Input{
        .rules = resolved_rules,
        .messages = split_lines(parts.at(1)),
    };
}

uint64_t part1(const Input& input) {
    std::regex re{"^" + input.rules.at(0) + "$"};

    auto matches = [&re](std::string_view m) {
        if (std::regex_match(std::string{m}, re)) return true;
        return false;
    };
    return std::ranges::count_if(input.messages, matches);
}

uint64_t part2(const Input& input) {
    return 0;
}

}}
