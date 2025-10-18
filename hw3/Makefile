# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Source and object files
SRCS = src/Point.cpp src/Line.cpp src/Rectangle.cpp src/Square.cpp test/test.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = hw3_tests

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each source file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)