set title 'Mi Gráfica'
set xlabel 'Nterms'
set ylabel 'Percentual difference'
set term pdf
set out "sumupdown.pdf"
#set log y

#w: plot styles -- lp: linespoints
#lt: line type
#lc: line color
#lw: line width
#pt: point type
#ps: pointsize
#t: title

plot 'data.txt' w lp lw 4 ps 2 pt 4 t 'data'


#Rangos para ejes x e y:

#Puedes especificar el rango para los ejes x e y 
#utilizando la sintaxis [xmin:xmax] para el eje x y 
#[ymin:ymax] para el eje y. Por ejemplo:

#plot [0:10] [0:20] 'data.txt' w lp


#Multiples conjuntos de datos:
#Puedes graficar varios conjuntos de datos en la misma 
#grafica separandolos por comas. Por ejemplo:

#plot 'data1.txt' w lp, 'data2.txt' w lp
