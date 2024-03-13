SHELL:=/bin/bash

all: main_factorial.x

%.x: %.o factorial.o
	g++ $^ -o $@

test_factorial.x: test_factorial.o factorial.o
	g++ $^ -o $@ -l Catch2Main -l Catch2

test: test_factorial.x
	./test_factorial.x

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o *.x