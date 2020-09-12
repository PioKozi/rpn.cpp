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
        // This bit feels kinda bad, anyone know how to make it less bad?
        if (parse_number(inp, num))
            s.push(num);
        // All the various operations are here :-)
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
        else if (inp == "^" || inp == "pow")
            s.pow();
        else if (inp == "log") // *arbitrary* log
            s.log();
        else if (inp == "log10")
            s.log10();
        else if (inp == "log2")
            s.log2();
        else if (inp == "ln") // natural log
            s.ln();
        // operations more to do with the stack than the numbers in it
        else if (inp == "del")
            s.del();
        else if (inp == "swap")
            s.swap();
        else if (inp == "up")
            s.cycle_up();
        else if (inp == "down")
            s.cycle_down();

        clear_screen(); // clears the screen before printing the new stack
        s.print_stack();
    }

    return 0;
}

// prints character to reset terminal. This may have side-effects, work on it later
void clear_screen()
{
    std::cout << "\033c";
}

// checks if the input is a number, also converts it to a double if it can be parsed
bool parse_number(const std::string &inp, double &num)
{
    char dummy;
    return std::sscanf(inp.c_str(), "%lf%c", &num, &dummy) == 1;
}
