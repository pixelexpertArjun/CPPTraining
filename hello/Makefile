CXX = g++
CXXFLAGS = -Wall -g
TARGET = container

SRCS = container.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run_valgrind 
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

run: $(TARGET)
	./$(TARGET)

run_valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(OBJS) $(TARGET)
