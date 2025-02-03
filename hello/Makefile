# CC = gcc
CXX = g++
CXXFLAGS = -Wall -g
# CPP = g++
# DEPS = api.h
# OBJ = hello.o api2.o

TARGET = oops2

SRCS = oops2.cpp
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

run_valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(OBJS) $(TARGET)
