#include <iostream>
#include <vector>
#include <cmath>

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
    void del()
    {
        stack.pop_back();
    }
    void print_stack()
    {
        for (auto i : stack) {
            std::cout << i << std::endl;
        }
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
};
