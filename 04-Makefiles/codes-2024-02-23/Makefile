all: sumupdown.pdf

sumupdown.x: sumupdown.cpp
	g++ sumupdown.cpp -o sumupdown.x

# %.x: %.cpp
#  	g++ $< -o $@

data.txt: sumupdown.x
	./sumupdown.x > data.txt

sumupdown.pdf: data.txt script.gp
	gnuplot script.gp
