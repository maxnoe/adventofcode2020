#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day11.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

namespace aocmaxnoe2020 { namespace day11 {


using seats_t = std::vector<std::vector<bool>>;
using neighbors_t = std::vector<std::vector<int>>;

void update_neighbors(const seats_t& seats, neighbors_t& neighbors) {
    size_t rows = seats.size();
    size_t cols = seats.at(0).size();

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            neighbors.at(row).at(col) = 0;

            for (int drow: {-1, 0, 1}) {
                for (int dcol: {-1, 0, 1}) {
                    if (drow == 0 && dcol == 0) continue;
                    size_t n_row = row + drow;
                    size_t n_col = col + dcol;
                    if (n_row >= rows || n_col >= cols) continue;
                    if (seats.at(n_row).at(n_col)) neighbors.at(row).at(col)++;
                }
            }
        }
    }
}

void update_occupied_in_sight(const std::vector<std::string_view>& lines, const seats_t& seats, neighbors_t& neighbors) {
    size_t rows = seats.size();
    size_t cols = seats.at(0).size();

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            neighbors.at(row).at(col) = 0;

            for (int drow: {-1, 0, 1}) {
                for (int dcol: {-1, 0, 1}) {
                    if (drow == 0 && dcol == 0) continue;
                    size_t n_row = row + drow;
                    size_t n_col = col + dcol;
                    while (n_row < rows && n_col < cols && lines[n_row][n_col] == '.') {
                        n_row += drow;
                        n_col += dcol;
                    }

                    if (n_row >= rows || n_col >= cols) continue;
                    if (seats.at(n_row).at(n_col)) neighbors.at(row).at(col)++;
                }
            }
        }
    }
}

size_t update_seats(const std::vector<std::string_view>& lines, seats_t& seats, const neighbors_t& neighbors) {
    size_t rows = seats.size();
    size_t cols = seats.at(0).size();

    size_t changed = 0;
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            if (lines.at(row).at(col) == '.') continue;

            if (seats.at(row).at(col) && neighbors.at(row).at(col) >=  4) {
                seats[row][col] = false;
                changed++;
            } else if (!seats[row][col] && neighbors[row][col] == 0) {
                seats[row][col] = true;
                changed++;
            }
        }
    }

    return changed;
}


size_t update_seats_2(const std::vector<std::string_view>& lines, seats_t& seats, const neighbors_t& neighbors) {
    size_t rows = seats.size();
    size_t cols = seats.at(0).size();

    size_t changed = 0;
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            if (lines.at(row).at(col) == '.') continue;

            if (seats.at(row).at(col) && neighbors.at(row).at(col) >=  5) {
                seats[row][col] = false;
                changed++;
            } else if (!seats[row][col] && neighbors[row][col] == 0) {
                seats[row][col] = true;
                changed++;
            }
        }
    }

    return changed;
}

uint64_t part1(const std::vector<std::string_view>& lines) {
    seats_t seats(lines.size(), std::vector<bool>(lines.at(0).size(), false));
    neighbors_t neighbors(lines.size(), std::vector<int>(lines[0].size(), 0));

    size_t n_steps = 0;
    while (update_seats(lines, seats, neighbors)) {
        n_steps++;
        update_neighbors(seats, neighbors);
    }
    
    size_t occupied = 0;
    for (const auto& row: seats) {
        occupied += std::ranges::count(row, true);
    }
    return occupied;
}

uint64_t part2(const std::vector<std::string_view>& lines) {
    seats_t seats(lines.size(), std::vector<bool>(lines.at(0).size(), false));
    neighbors_t neighbors(lines.size(), std::vector<int>(lines[0].size(), 0));

    size_t n_steps = 0;
    while (update_seats_2(lines, seats, neighbors)) {
        n_steps++;
        update_occupied_in_sight(lines, seats, neighbors);
    }
    
    size_t occupied = 0;
    for (const auto& row: seats) {
        occupied += std::ranges::count(row, true);
    }
    return occupied;
}

}}
