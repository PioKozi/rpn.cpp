#include "./rpn.cpp"

#include <iostream>
#include <string>

void clear_screen();
bool is_number(std::string);

int main()
{
    rpnstack test;

    std::cout << "Exit with ^C\n" << std::endl;

    while (true) {
        std::string inp;
        std::cin >> inp;
        if (is_number(inp))
            test.push(std::stod(inp));
        else if (inp == "+" || inp == "add") {
            test.add();
        }
        if (inp == "-" || inp == "sub") {
            test.add();
        }
        if (inp == "*" || inp == "mult") {
            test.add();
        }
        if (inp == "/" || inp == "div") {
            test.add();
        }
        clear_screen();
        test.print_stack();
    }

    return 0;
}

// prints character to reset terminal. This has side-effects, work on it later
void clear_screen()
{
    std::cout << "\033c";
}

// checks if the input is a number, floating point true
bool is_number(std::string inp)
{
    for (char i : inp)
        if (!isdigit(i) && i != '.')
            return false;
    return true;
}
