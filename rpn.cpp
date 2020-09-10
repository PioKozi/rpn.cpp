#include <iostream>
#include <vector>

struct rpnstack {
private:
    std::vector<double> stack;

    double pop()
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
        this->push(op(a, b));
    }

public:
    void push(double a) { stack.push_back(a); }
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
    void mult()
    {
        this->two_op([](auto l, auto r) { return l * r; });
    }
    void div()
    {
        this->two_op([](auto l, auto r) { return l / r; });
    }
};
