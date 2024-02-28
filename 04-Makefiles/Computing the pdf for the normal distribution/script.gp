set title 'Aproximation of a Probability Density Function of Normal Distribution '
set xlabel 'x'
set ylabel 'F(x)'
set term pdf
set out "random_pdf.pdf"
set grid xtics ytics lc rgb "#808080" lw 0.5

#set log y


#plot 'data.txt' w lp lw 4 ps 2 pt 4 t 'data'
#plot 'random_pdf_seed_1.txt' w lp lt 1 t 'seed = 1', 'random_pdf_seed_2.txt' w lp lt 2 t 'seed =2', 'random_pdf_seed_5.txt' w lp lt 5 t 'seed =5',
plot 'random_pdf_seed_1.txt' with points pt 8 ps 0.5 t 'seed = 1', 'random_pdf_seed_2.txt' with points pt 7 ps 0.5 t 'seed =2', 'random_pdf_seed_5.txt' with points pt 9 ps 0.5 t 'seed =5',

#Rangos para ejes x e y:

#Puedes especificar el rango para los ejes x e y 
#utilizando la sintaxis [xmin:xmax] para el eje x y 
#[ymin:ymax] para el eje y. Por ejemplo:

#plot [0:10] [0:20] 'data.txt' w lp


#Multiples conjuntos de datos:
#Puedes graficar varios conjuntos de datos en la misma 
#grafica separandolos por comas. Por ejemplo:

#plot 'data1.txt' w lp, 'data2.txt' w lp
