#-------------------------------------------------------------------------+
# Fichier de commandes gnuplot : ex2/output/Puissance/Puissance_x=2.0.plt |
#-------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "PUISSANCE"
set grid
set terminal png
set output 'ex2/output/Puissance/png/Puissance_x=2.0_op.png'
plot 'ex2/output/Puissance/Puissance_x=2.0.dat' using 1:2 title 'x=2.0'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'ex2/output/Puissance/png/Puissance_x=2.0_cmp.png'
plot 'ex2/output/Puissance/Puissance_x=2.0.dat' using 1:3 title 'x=2.0'
quit
