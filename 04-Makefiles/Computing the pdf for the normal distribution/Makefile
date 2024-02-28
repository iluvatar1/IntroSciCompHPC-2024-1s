# Opciones de compilación
CFLAGS = -std=c++11
# Compilador
CC = g++
# Nombre del ejecutable
TARGET = programa

DATA_FILES = random_pdf_seed_1.txt random_pdf_seed_2.txt random_pdf_seed_5.txt  # Lista de archivos de datos
PDF_FILES = $(patsubst %.txt, %.pdf, $(DATA_FILES))  # Lista de archivos PDF generados

all: $(PDF_FILES)

# Regla para construir el programa
$(TARGET): random_pdf.cpp
	$(CC) $(CFLAGS) -o $(TARGET) random_pdf.cpp

# Regla para ejecutar el programa con semilla 1
run_seed_1: $(TARGET)
	./$(TARGET) 1 5000 3.5 0.4 2.7 4.6 50

# Regla para ejecutar el programa con semilla 2
run_seed_2: $(TARGET)
	./$(TARGET) 2 5000 3.5 0.4 2.7 4.6 50

# Regla para ejecutar el programa con semilla 5
run_seed_5: $(TARGET)
	./$(TARGET) 5 5000 3.5 0.4 2.7 4.6 50

# Regla para generar el gráfico usando gnuplot
plot: $(DATA_FILES) script.gp
	gnuplot script.gp

# # Regla para generar el gráfico usando gnuplot
# %.pdf: %.txt script.gp
# 	gnuplot  script.gp

#-e "inputfile='$<'; outputfile='$@'"




# Regla para limpiar archivos generados

.PHONY: clean

clean:
	rm -f $(TARGET) $(PDF_FILES)