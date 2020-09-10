#include <cmath>
#include <iostream>
#include <vector>
#include <limits>

struct rpnstack {
private:
    std::vector<double> stack;

    auto pop()
    {
        auto ret = stack.back();
        stack.pop_back();
        return ret;
    }

    // operations that require 2 operands
    void two_op(double (*op)(double, double))
    {
        auto a = this->pop();
        auto b = this->pop();
        // r->l, because l is more recent than r (like would be r in algebraic)
        this->push(op(b, a));
    }

public:
    void push(double a) { stack.push_back(a); }
    void swap()
    {
        auto a                  = stack[stack.size() - 1];
        auto b                  = stack[stack.size() - 2];
        stack[stack.size() - 1] = b;
        stack[stack.size() - 2] = a;
    }
    void del() { stack.pop_back(); }
    void print_stack()
    {
        std::cout.precision(std::numeric_limits<double>::max_digits10);
        for (auto i : stack) {
            std::cout << std::fixed << i << std::endl;
        }
    }
    void cycle_up()
    {
        auto a = this->pop();
        stack.insert(stack.begin(), a);
    }
    void cycle_down()
    {
        auto a = stack[0];
        stack.erase(stack.begin());
        stack.push_back(a);
    }

    // Basic 2 operand operations
    void add()
    {
        this->two_op([](auto l, auto r) { return l + r; });
    }
    void sub()
    {
        this->two_op([](auto l, auto r) { return l - r; });
    }
    void mul()
    {
        this->two_op([](auto l, auto r) { return l * r; });
    }
    void div()
    {
        this->two_op([](auto l, auto r) { return l / r; });
    }
    void mod()
    {
        this->two_op([](auto l, auto r) { return std::fmod(l, r); });
    }
    void pow()
    {
        this->two_op([](auto l, auto r) { return std::pow(l, r); });
    }
};
