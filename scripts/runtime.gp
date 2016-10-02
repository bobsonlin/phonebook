reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'optimized (struct)', \
'' using 5:xtic(1) with histogram title 'optimized (fgets)' , \
'' using ($0-0.06):($2+0.005):2 with labels title ' ', \
'' using ($0+0.2):($3+0.005):3 with labels title ' ', \
'' using ($0+0.5):($5+0.002):5 with labels title ' '
