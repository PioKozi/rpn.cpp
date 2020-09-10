#include <iostream>
#include <vector>

struct rpnstack {
private:
    std::vector<long double> stack;

    auto pop()
    {
        auto ret = stack.back();
        stack.pop_back();
        return ret;
    }

    // operations that require 2 operands
    void two_op(long double (*op)(long double, long double))
    {
        auto a = this->pop();
        auto b = this->pop();
        std::cout << "This is a test of make" << std::endl;
        this->push(op(a, b));
    }

public:
    void push(long double a) { stack.push_back(a); }
    void print_stack()
    {
        for (auto i : stack) {
            std::cout << i << std::endl;
        }
    }

    // Basic 2 operand operations
    void add()
    {
        this->two_op([](auto l, auto r) { return r + l; });
    }
    void sub()
    {
        this->two_op([](auto l, auto r) { return r - l; });
    }
    void mult()
    {
        this->two_op([](auto l, auto r) { return r * l; });
    }
    void div()
    {
        this->two_op([](auto l, auto r) { return r / l; });
    }
};
