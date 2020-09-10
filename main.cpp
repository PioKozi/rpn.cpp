#include "./rpn.cpp"

#include <cstdio>
#include <iostream>
#include <string>

void clear_screen();
bool parse_number(const std::string &, double &);

int main()
{
    rpnstack s;

    std::cout << "Exit with ^C\n" << std::endl;

    while (true) {
        std::string inp;
        std::cin >> inp;
        double num = 0;
        if (parse_number(inp, num))
            s.push(num);
        else if (inp == "+" || inp == "add")
            s.add();
        else if (inp == "-" || inp == "sub")
            s.sub();
        else if (inp == "*" || inp == "mul")
            s.mul();
        else if (inp == "/" || inp == "div")
            s.div();
        else if (inp == "%" || inp == "mod")
            s.mod();
        else if (inp == "del")
            s.del();
        else if (inp == "swap")
            s.swap();

        clear_screen();
        s.print_stack();
    }

    return 0;
}

// prints character to reset terminal. This has side-effects, work on it later
void clear_screen()
{
    std::cout << "\033c";
}

// checks if the input is a number, floating point true
bool parse_number(const std::string &inp, double &num)
{
    char dummy;
    return std::sscanf(inp.c_str(), "%lf%c", &num, &dummy) == 1;
}
