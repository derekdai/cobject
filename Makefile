SRC=test.c object.c shape.c point.c circle.c line.c

SRCXX=test.cpp

CFLAGS=-g -Werror

CXXFLAGS=$(CFLAGS) -std=c++11

all: test testpp

test: $(SRC)
	$(CC) $(CFLAGS) -o test $(SRC)
	
testpp: $(SRCXX)
	$(CXX) $(CXXFLAGS) -o testpp $(SRCXX)
	
clean:
	rm -rf test testpp
