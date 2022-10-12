#-------------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : TriFusion/output/Tri_fusion/Tri_fusion_aleatoire.plt |
#-------------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI FUSION"
set grid
set terminal png
set output 'TriFusion/output/Tri_fusion/png/Tri_fusion_aleatoire_op.png'
plot 'TriFusion/output/Tri_fusion/Tri_fusion_aleatoire.dat' using 1:2 title 'aleatoire'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'TriFusion/output/Tri_fusion/png/Tri_fusion_aleatoire_cmp.png'
plot 'TriFusion/output/Tri_fusion/Tri_fusion_aleatoire.dat' using 1:3 title 'aleatoire'
quit
