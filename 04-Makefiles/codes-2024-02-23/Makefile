CXXFLAGS=-O2 -std=c++17

all: sumupdown.pdf

#sumupdown.x: sumupdown.cpp
#	g++ $(CXXFLAGS) sumupdown.cpp -o sumupdown.x
%.x: %.cpp
	g++ $(CXXFLAGS) $^ -o $@

data.txt: sumupdown.x
	./sumupdown.x > data.txt

sumupdown.pdf: script.gp data.txt
	gnuplot script.gp

.PHONY: clean 

clean: 
	rm -f *.x *.txt *.pdf 