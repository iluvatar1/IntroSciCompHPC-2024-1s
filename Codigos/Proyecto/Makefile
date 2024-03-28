all: punto1.pdf

punto1.x: punto1.cpp
	g++ punto1.cpp -o punto1.x

data.txt: punto1.x
	./punto1.x > data.txt

punto1.pdf: script.gp data.txt
	gnuplot script.gp