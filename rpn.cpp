#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

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
        if (stack.size() < 2)
            return;
        auto a = this->pop();
        auto b = this->pop();
        // r->l, because l is more recent than r (like would be r in algebraic)
        this->push(op(b, a));
    }

    // operations that require 1 operand
    void one_op(double (*op)(double))
    {
        if (stack.size() < 1)
            return;
        auto a                  = stack[stack.size() - 1];
        stack[stack.size() - 1] = op(a);
    }

public:
    void push(double a) { stack.push_back(a); }
    void swap()
    {
        if (stack.size() < 2)
            return;
        auto a                  = stack[stack.size() - 1];
        auto b                  = stack[stack.size() - 2];
        stack[stack.size() - 1] = b;
        stack[stack.size() - 2] = a;
    }
    void del()
    {
        if (stack.size() < 1)
            return;
        stack.pop_back();
    }
    void print_stack()
    {
        std::cout.precision(std::numeric_limits<double>::max_digits10);
        for (auto i : stack) {
            std::cout << std::fixed << i << std::endl;
        }
    }
    void cycle_down()
    {
        auto a = this->pop();
        stack.insert(stack.begin(), a);
    }
    void cycle_up()
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
    void log()  // arbitrary base logarithm
    {
        this->two_op([](auto l, auto r) { return std::log(l) / std::log(r); });
    }

    // Basic 1 operand operations
    void ln()
    {
        this->one_op([](auto n) { return std::log(n); });
    }
    void log10()
    {
        this->one_op([](auto n) { return std::log10(n); });
    }
    void log2()
    {
        this->one_op([](auto n) { return std::log2(n); });
    }
};
