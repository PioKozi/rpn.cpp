#include "./rpn.cpp"

#include <iostream>
#include <string>

// prints character to reset terminal. This has side-effects, work on it later
void clear_screen()
{
    std::cout << "\033c";
}

int main()
{
    rpnstack test;

    clear_screen();

    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);

    test.print_stack();

    test.add();

    test.print_stack();
    return 0;
}
