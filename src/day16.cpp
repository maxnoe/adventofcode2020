#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day16.h>
#include <numeric>
#include <ranges>
#include <regex>
#include <unordered_set>

using std::views::values;
using std::views::keys;
using std::views::filter;


namespace aocmaxnoe2020 { namespace day16 {

Input parse_input(std::string_view s) {
    Input input;

    auto parts = split(s, "\n\n");
    if (parts.size() != 3) throw std::runtime_error("Input not split into 3 parts");

    std::regex re{R"(([\w\s]+): (\d+)-(\d+) or (\d+)-(\d+))"};
    std::smatch match;

    for (auto line: split_lines(parts[0])) {
        std::string line_str{line};
        if (!std::regex_match(line_str, match, re)) {
            throw std::runtime_error("Regex did not match: " + line_str);
        }

        input.specifications[match[1]] = {
            .min1 = std::stoi(match[2]),
            .max1 = std::stoi(match[3]),
            .min2 = std::stoi(match[4]),
            .max2 = std::stoi(match[5]),
        };
    }

    auto lines2 = split_lines(parts[1]);
    if (lines2.size() != 2 || lines2[0] != "your ticket:") throw std::runtime_error("Did not find 'your ticket':" + std::string{lines2[0]});
    auto numbers = split(lines2[1], ",");
    input.my_ticket.reserve(numbers.size());
    for (auto number: numbers) {
        input.my_ticket.push_back(std::stoi(std::string{number}));
    }

    for (auto line: split_lines(parts[2])) {
        if (line == "nearby tickets:") continue;

        input.nearby_tickets.emplace_back();
        for (auto number: split(line, ",")) {
            input.nearby_tickets.back().push_back(std::stoi(std::string{number}));
        }

    }

    return input;
}

bool is_field_valid(const std::unordered_map<std::string, Specification>& specs, int val) {
    return std::ranges::any_of(values(specs), [&val](const auto& s) {return s.validate(val);});
}


uint64_t part1(const Input& input) {
    auto error_rate = [&input](auto sum, const auto& ticket) {
        for (auto val: ticket) {
            bool valid = is_field_valid(input.specifications, val);
            if (!valid) {
                sum += val;
            }
        }
        return sum;
    };
    return std::accumulate(input.nearby_tickets.begin(), input.nearby_tickets.end(), 0, error_rate);
}

using positions_t = std::unordered_map<std::string, std::unordered_set<int>>;
using specs_t = const std::unordered_map<std::string, Specification>;

positions_t init_positions(specs_t& specs, size_t n_fields) {
    positions_t possible_positions;
    possible_positions.reserve(specs.size());

    for (const auto& k: keys(specs)) {
        possible_positions.emplace(k, n_fields);
        for (size_t f = 0; f < n_fields; f++) {
            possible_positions[k].insert(f);
        }
    }

    return possible_positions;

}

using tickets_t = std::vector<std::vector<int>>;

tickets_t get_valid_tickets(const tickets_t& tickets, const specs_t& specs) {
    auto is_valid_field = [&specs](auto v) {return is_field_valid(specs, v);};
    auto is_valid_ticket = [&is_valid_field](const auto& ticket) {
        return std::ranges::all_of(ticket, is_valid_field);
    };

    std::vector<std::vector<int>> valid_tickets;
    for (const auto& ticket: tickets | filter(is_valid_ticket)) {
        valid_tickets.push_back(ticket);
    }

    return valid_tickets;
}


uint64_t part2(const Input& input) {
    size_t n_fields = input.my_ticket.size();
    const auto& specs = input.specifications;

    positions_t possible_positions = init_positions(specs, n_fields);
    tickets_t valid_tickets = get_valid_tickets(input.nearby_tickets, specs);

    std::unordered_map<std::string, int> field_indices;

    while (field_indices.size() < n_fields) {
        for (const auto& [key, spec]: input.specifications) {
            auto& current = possible_positions.at(key);

            if (field_indices.contains(key)) continue;

            if (current.size() == 1) {
                int found = *current.begin();
                std::cout << key << " is at " << found << std::endl;
                field_indices[key] = found;

                for (auto& [other_key, positions]: possible_positions) {
                    if (key != other_key) {
                        positions.erase(found);
                    }
                }
                continue;
            }

            auto it = current.cbegin();
            while (it != current.cend()) {
                int field = *it;

                auto field_valid = [&spec,  &field](const std::vector<int>& ticket) {
                    return spec.validate(ticket.at(field));
                };

                bool possible = std::ranges::all_of(valid_tickets,  field_valid);
                it = possible ? std::next(it) : current.erase(it);
            }
        }
    }

    uint64_t result = 1;
    for (const auto& [k, v]: field_indices) {
        if (k.starts_with("departure")) {
            result *= input.my_ticket.at(v);
        }
    }

    return result;
}


}}
