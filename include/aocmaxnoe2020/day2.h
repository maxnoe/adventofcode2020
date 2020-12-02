#ifndef DAY2_H
#define DAY2_H

#include <string>
#include <vector>

namespace aocmaxnoe2020 { namespace day2 {

struct PasswordSpec {
    int min_count = 0;
    int max_count = 0;
    char character = 0;
    std::string password;

    PasswordSpec(int min_count, int max_count, char character, std::string password) 
        : min_count(min_count), max_count(max_count), character(character), password(password) {}

    PasswordSpec(const std::string& password_spec);

    bool is_valid_part1() const;
    bool is_valid_part2() const;
};

std::vector<PasswordSpec> parse_input(const std::string& input);

bool operator==(const PasswordSpec& lhs, const PasswordSpec& rhs);
std::ostream& operator<<(std::ostream& os, const PasswordSpec& pwd);

int part1(const std::vector<PasswordSpec>& passwords);
int part2(const std::vector<PasswordSpec>& passwords);

}}


#endif /* ifndef DAY2_H */
