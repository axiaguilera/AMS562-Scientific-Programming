
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Build the main executable
all: ams562_hw2

# Link object files to create executable
ams562_hw2: ams562_hw2.o prime.o
	$(CXX) $(CXXFLAGS) -o ams562_hw2 ams562_hw2.o prime.o

# Compile ams562_hw2.cpp
ams562_hw2.o: ams562_hw2.cpp prime.h
	$(CXX) $(CXXFLAGS) -c ams562_hw2.cpp

# Compile prime.cpp
prime.o: prime.cpp prime.h
	$(CXX) $(CXXFLAGS) -c prime.cpp

# Clean up object files and executable
clean:
	rm -f *.o ams562_hw2
