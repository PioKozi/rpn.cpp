CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic -O0 -g -std=c++17

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = $(shell basename $(CURDIR))

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(EXECUTABLE)

$(OBJECTS) : $(SOURCES)
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
