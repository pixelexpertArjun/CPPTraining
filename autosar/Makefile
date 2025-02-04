

CXX = g++
CXXFLAGS = -Wall -g

TARGET = process_smrtptr

SRCS = process_smrtptr.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run 
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
