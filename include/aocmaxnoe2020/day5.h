#ifndef DAY3_H
#define DAY3_H

#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<string_view>


namespace aocmaxnoe2020 { namespace day5 {

using boarding_pass_t = std::pair<int, int>;

const int N_ROWS = 128;
const int N_COLS = 8;
const int N_SEATS = N_ROWS * N_COLS;

boarding_pass_t parse_pass(std::string_view line);
int pass_id(const boarding_pass_t& pass);
std::pair<int, int> day5(std::string_view input);

}}


#endif /* ifndef DAY3_H */
