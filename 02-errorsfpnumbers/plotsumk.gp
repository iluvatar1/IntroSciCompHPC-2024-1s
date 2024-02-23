set xlbel 'k'
set ylabel 'f(k)'
set term pdf
set out "fk.pdf"
set log y
plot 'data.txt' w lp lw 4 ps 1 pt 4 t 'data'
#test