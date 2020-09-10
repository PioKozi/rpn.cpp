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
        // r->l, because l is more recent than r (like would be r in algebraic)
        this->push(op(b, a));
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
