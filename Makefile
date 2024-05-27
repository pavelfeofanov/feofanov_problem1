CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main
SRCS = main.cpp Parser.cpp Solver.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(TARGET) $(OBJS)
