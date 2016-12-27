
CXX = g++
CCFLAG = -Wall -Isrc
LD = g++
LDFLAGS = -Wall

SRCS := $(wildcard src/*.cpp)
TARGETLIST:=$(patsubst src/%.cpp,%,$(SRCS))
OBJS := $(patsubst %cpp,%o,$(SRCS))  

all: clean $(TARGETLIST)

$(OBJS): %.o: %.cpp
	$(CXX) $(CCFLAG) -c $< -o $@

$(TARGETLIST): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ src/$@.o
	
clean:
	rm -rf $(OBJS) $(TARGETLIST)
	