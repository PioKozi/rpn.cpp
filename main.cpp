#include "./rpn.cpp"

int main()
{
    rpnstack test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);

    test.print_stack();

    test.add();

    test.print_stack();
    return 0;
}
