# 二叉树算法

CCFLAG = -Wall
CXX = g++

SRCS := $(wildcard src/*.cpp)
BIN_NAME := $(patsubst src/%.cpp,bin/%,$(SRCS))
OBJS := $(patsubst %cpp,%o,$(SRCS))  

all: clean $(BIN_NAME)

$(BIN_NAME): $(OBJS)
	$(CXX) $(CCFLAG) -o $@ $^

$(OBJS): %.o: %.cpp
	$(CXX) -c $< -o $@ $(CCFLAG)

clean:
	rm -rf $(BIN_NAME)
	rm -rf $(OBJS)
	