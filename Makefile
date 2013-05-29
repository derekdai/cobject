SRC=test.c shape.c
SRCXX=test.cpp

all: test testpp

test: $(SRC)
	$(CC) -o test $(SRC)
	
testpp: $(SRCXX)
	$(CXX) -std=c++11 -o testpp $(SRCXX)
	
clean:
	rm -rf test testpp
