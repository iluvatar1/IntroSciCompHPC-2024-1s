#Bandera que se lo colva al compildor
CXXFLAGS=-o2 -std=c++17 

all: graph.pdf

# sumupdown.x: sumupdown.cpp
# 	g++  sumupdown.cpp -o sumupdown.x

# sumupdown.x: sumupdown.cpp
# 	g++ $(CXXFLAGS) sumupdown.cpp -o sumupdown.x

#Establece la dependencia entre los archivos con extension
#.cpp y lso archivos ejecutables con extension .x

#La notacion % es un comodin que coincide con cualquier
#cadena de caracteres

# $^: Es una variable automática que representa todas
#las dependencias. En este caso, representa el archivo
#fuente ('%.cpp')

# -o $@: Especifica el nombre del archivo de salida.
# $@ es una variable automatica que representa el objeto
# de la regla, en este caso, el archivo ejecutable 
#(%x)

%.x: %.cpp
	g++ $(CXXFLAGS) $^ -o $@

data.txt: gamma.x
	./gamma.x > data.txt

graph.pdf: data.txt script.gp
	gnuplot script.gp


.PHONY: clean

clean:
	rm -f *.x *.txt *.pdf