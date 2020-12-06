#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day6.h>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

namespace aocmaxnoe2020 { namespace day6 {

using std::views::transform;
using std::views::filter;


std::vector<group_t> parse_input(std::string_view input){
    auto groups = split(input, "\n\n");
    std::vector<group_t> ret;
    ret.reserve(groups.size());
    for (auto group: groups) {
        ret.push_back(split_lines(group));
    }
    return ret;
}

int count_unique_questions(group_t group) {
    std::unordered_set<char> counts;
    for (auto member: group) {
        for (char c: member) {
            counts.insert(c);
        }
    }
    return counts.size();
}

int count_given_by_all_members(group_t group) {
    std::unordered_map<char, size_t> counts;
    for (auto member: group) {
        for (char c: member) {
            if (!counts.contains(c)) {
                counts[c] = 0;
            }
            counts[c]++;
        }
    }

    int byall = 0;
    for (size_t count: std::views::values(counts)) {
        if (count == group.size()) {
            byall++;
        }
    }

    return byall;
}

int part1(const std::vector<group_t>& groups) {
    // bummer that there is no std::ranges::accumulate in cpp20
    int n_total = 0;
    for (int n: groups | transform(count_unique_questions)) {
        n_total += n;
    }
    return n_total;
}

int part2(const std::vector<group_t>& groups) {
    // bummer that there is no std::ranges::accumulate in cpp20
    int n_total = 0;
    for (int n: groups | transform(count_given_by_all_members)) {
        n_total += n;
    }
    return n_total;
}

}}

