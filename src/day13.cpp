#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day13.h>
#include <vector>
#include <ranges>
#include <algorithm>
#include <limits>

namespace aocmaxnoe2020 { namespace day13 {

using std::views::take;
using std::ranges::all_of;


std::pair<int, busses_t> parse_input(std::string_view input) {
    auto lines = split_lines(input);
    int min_time = std::stoi(std::string{lines.at(0)});

    auto bus_inputs = split(lines.at(1), ",");
    busses_t busses;
    busses.reserve(bus_inputs.size());

    for (auto bus: bus_inputs) {
        if (bus == "x") {
            busses.push_back(-1);
        } else {
            busses.push_back(std::stoi(std::string{bus}));
        }
    }
    return std::make_pair(min_time, busses);
}

int calc_wait_time(int min_time, int bus) {
    return bus - min_time % bus;
}

bool in_service(int period) {
    return period != -1;
}

int part1(int min_time, const busses_t& busses) {
    int min_wait_time = std::numeric_limits<int>::max();
    int best_bus = -1;
    for (int bus: busses | std::views::filter(in_service)) {
        int wait_time = calc_wait_time(min_time, bus);
        if (wait_time < min_wait_time) {
            min_wait_time = wait_time;
            best_bus = bus;
        }
    }

    return best_bus * min_wait_time;
}

uint64_t part2(const busses_t& busses) {
    std::vector<std::pair<int, int>> bus_requirements;

    for (size_t offset = 0; offset < busses.size(); offset++) {
        int period = busses.at(offset);
        if (!in_service(period)) continue;
        bus_requirements.emplace_back(period, offset);
    }

    uint64_t t = 0;
    uint64_t step = 1;
    bool found = false;
    auto is_there = [&t](const auto& p) {return ((t + p.second) % p.first) == 0;};

    for (size_t i = 0; i < bus_requirements.size(); i++) {
        while(!(found = all_of(bus_requirements | take(i + 1), is_there))) {
            t += step;
        }
        step *= bus_requirements.at(i).first;
    }

    return t;
}


}}
