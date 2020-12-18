#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day18.h>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <ranges>


namespace aocmaxnoe2020 { namespace day18 {


Expression::ptr_t parse_expression(std::string_view s) {
    size_t parentheses_open = 0;

    Expression::ptr_t expr = nullptr;

    size_t parentheses_pos = 0;

    for (size_t pos = 0; pos < s.size(); pos++) {
        
        // handle parentheses first
        switch (s.at(pos)) {
            case '(':
                if (parentheses_open == 0) parentheses_pos = pos;
                parentheses_open++;
                continue;
            case ')':
                parentheses_open--;
                if (parentheses_open == 0) {
                    auto new_expr = parse_expression(s.substr(parentheses_pos + 1, pos - parentheses_pos - 1));
                    if (expr == nullptr) {
                        expr = std::move(new_expr);
                    } else {
                        dynamic_cast<BinaryOp*>(expr.get())->right_ = std::move(new_expr);
                    }
                }
                continue;
            default: break;
        }

        if (parentheses_open > 0) continue;

        // new literal constant
        if ((s.at(pos) >= '0') && (s.at(pos) <= '9')) {
            auto constant = std::make_unique<Constant>(s.at(pos) - '0');
            if (expr == nullptr) {
                expr = std::move(constant);
            } else {
                dynamic_cast<BinaryOp*>(expr.get())->right_ = std::move(constant);
            }
            continue;
        }

        switch (s.at(pos)) {
            case '+': 
                expr = std::make_unique<Addition>(std::move(expr), nullptr);
                break;
            case '*': 
                expr = std::make_unique<Multiplication>(std::move(expr), nullptr);
                break;
            default: throw std::runtime_error("Unexpected case");
        }
    }    

    return expr;
}


expressions_t parse_input(std::string_view input) {
    expressions_t expressions;

    for (auto line: split_lines(input)) {
        std::string s{line};
        s.erase(std::ranges::remove(s, ' ').begin(), s.end());
        expressions.push_back(parse_expression(s));
    }

    return expressions;
}

uint64_t part1(const expressions_t& input) {
    auto eval = [](uint64_t acc, const std::shared_ptr<Expression>& expr) {
        return acc + expr->evaluate();
    };
    return std::accumulate(input.begin(), input.end(), 0ull, eval);
}

uint64_t part2(const expressions_t& input) {
    return 0;
}

}}
