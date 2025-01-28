# CC = gcc
CXX = g++
CXXFLAGS = -Wall -g
# CPP = g++
# DEPS = api.h
# OBJ = hello.o api2.o

TARGET = main

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# %.o: %.c $(DEPS)
  # $(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# hellomake: $(OBJ)
 # $(CC) -o $@ $^ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(OBJS) $(TARGET)
