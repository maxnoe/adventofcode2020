#ifndef day18_H
#define day18_H

#include <vector>
#include <memory>
#include <aocmaxnoe2020/aocmaxnoe2020.h>


namespace aocmaxnoe2020 { namespace day18 {

class Expression {
    public:
        Expression() = default;
        using ptr_t = std::unique_ptr<Expression>;

        virtual ~Expression() = default;
        virtual uint64_t evaluate() = 0;
        virtual std::string toString() = 0;
};

class Constant: public Expression {

    protected:
        int value_ = 0;
    public:
        Constant(int value): value_(value) {}
        uint64_t evaluate() override {return value_;}
        std::string toString() override {return std::to_string(value_);}
};

class BinaryOp: public Expression {
    public:
        BinaryOp(Expression::ptr_t left, Expression::ptr_t right) :
            left_(std::move(left)), right_(std::move(right)) {}

        std::unique_ptr<Expression> left_;
        std::unique_ptr<Expression> right_;
};

class Addition : public BinaryOp {
    using BinaryOp::BinaryOp;
    public:
        uint64_t evaluate() override {
            if (left_ == nullptr) throw std::runtime_error("Left is nullptr");
            if (right_ == nullptr) throw std::runtime_error("right is nullptr");
            return left_->evaluate() + right_->evaluate();
        }
        std::string toString() override {
            std::string l = left_ == nullptr ? "null" : left_->toString();
            std::string r = right_ == nullptr ? "null" : right_->toString();
            return "(" + l + " + " + r + ")";
        }
};

class Multiplication : public BinaryOp {
    using BinaryOp::BinaryOp;
    public:
        uint64_t evaluate() override {
            if (left_ == nullptr) throw std::runtime_error("Left is nullptr");
            if (right_ == nullptr) throw std::runtime_error("right is nullptr");
            return left_->evaluate() * right_->evaluate();
        }
        std::string toString() override {
            std::string l = left_ == nullptr ? "null" : left_->toString();
            std::string r = right_ == nullptr ? "null" : right_->toString();
            return "(" + l + " * " + r + ")";
        }
};

using expressions_t = std::vector<std::shared_ptr<Expression>>;

expressions_t parse_input(std::string_view input);
uint64_t part1(const expressions_t& input);
uint64_t part2(const expressions_t& input);

}}


#endif /* ifndef day18_H */
