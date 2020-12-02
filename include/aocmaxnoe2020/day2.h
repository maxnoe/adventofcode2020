#ifndef DAY2_H
#define DAY2_H

#include <string>
#include <vector>
#include <functional>

namespace aocmaxnoe2020 { namespace day2 {

struct PasswordSpec {
    int min_count = 0;
    int max_count = 0;
    char character = 0;
    std::string password;
};

using checker_t = std::function<bool(const PasswordSpec&)>;

PasswordSpec parse_line(const std::string& line);
std::vector<PasswordSpec> parse_input(const std::string& input);

bool operator==(const PasswordSpec& lhs, const PasswordSpec& rhs);
std::ostream& operator<<(std::ostream& os, const PasswordSpec& pwd);

bool check_validity_part1(const PasswordSpec& pwd);
bool check_validity_part2(const PasswordSpec& pwd);
int count_valid_passwords(const std::vector<PasswordSpec>& passwords, checker_t checker);
int part1(const std::vector<PasswordSpec>& passwords);
int part2(const std::vector<PasswordSpec>& passwords);


}}


#endif /* ifndef DAY2_H */
