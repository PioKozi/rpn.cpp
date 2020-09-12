# RPN.CPP

## What

This is just a very simple RPN calculator written in C++. The UI is
also just a terminal. I wrote this in about one day, so you'd expect
it to be pretty limited in what it can do. Maybe it'll become more
later, but that's unknown.

## Compilation

It just uses standard library C++ stuff. Maybe that'll be worth
changing that later for greater precision.

```bash
git clone https://github.com/PioKozi/rpn.cpp.git
cd rpn.cpp
make
```

## Usage

`./RPN`

From there on it should be like a normal RPN calculator.
Mind, it will also clear your screen. If you don't want that, you can
remove the [relevant function call in the code](https://github.com/PioKozi/rpn.cpp/blob/master/main.cpp#L54)

## Documentation

Codebase isn't large, operations can be found in main.cpp, in that
chain of if/if else statements. Otherwise, it should do what you'd
expect of an RPN calculator. So there's not any real documentation,
nor do I expect there will be a need for any.

## Contributing

I have no idea why you would want to do anything with this, but if you
want to, sure.

I haven't used C++ that much, don't know it all that well, but I'll
try to understand things if they're somewhat advanced. Problems would
be when things start looking weird and obscure, so please don't do
that.

Also throw the code through `clang-format`. There's a `.clang-format`
file with my rules in there.

Please be nice :-)

## License

MIT License, see LICENSE file.
