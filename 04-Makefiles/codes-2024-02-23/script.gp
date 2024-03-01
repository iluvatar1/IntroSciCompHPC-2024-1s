set term pdf
set out "sumupdown.pdf"
set xlabel "Nterms"
set ylabel "Percentual difference"
set log y
plot 'data.txt' u 1:4 w lp pt 6 ps 0.5
