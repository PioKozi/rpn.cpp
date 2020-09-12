# RPN.CPP

## What

This is just a very simple RPN calculator written in C++. The UI is
also just a terminal. I wrote this in about one day, so you'd expect
it to be pretty limited in what it can do. Maybe it'll become more
later, but that's unknown.

## Compilation

It just uses standard library C++ stuff. Maybe that'll be worth
changing that later for greater precision.

`git clone https://github.com/PioKozi/rpn.cpp.git`
`cd rpn.cpp`
`make`

## Usage

`./RPN`

From there on it should be like a normal RPN calculator.
Mind, it will also clear your screen. If you don't want that, you can
remove the [relevant function call in the code](https://github.com/PioKozi/rpn.cpp/blob/master/main.cpp#L51)

## Documentation

Codebase isn't large, operations can be found in main.cpp, in that
chain of if/if else statements. Otherwise, it should do what you'd
expect of an RPN calculator. So there's not any real documentation,
nor do I expect there will be a need for any.

## License

MIT License, see LICENSE file.
