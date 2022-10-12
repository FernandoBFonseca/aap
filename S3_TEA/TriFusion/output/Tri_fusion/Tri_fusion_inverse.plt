#-----------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : TriFusion/output/Tri_fusion/Tri_fusion_inverse.plt |
#-----------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI FUSION"
set grid
set terminal png
set output 'TriFusion/output/Tri_fusion/png/Tri_fusion_inverse_op.png'
plot 'TriFusion/output/Tri_fusion/Tri_fusion_inverse.dat' using 1:2 title 'inverse'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'TriFusion/output/Tri_fusion/png/Tri_fusion_inverse_cmp.png'
plot 'TriFusion/output/Tri_fusion/Tri_fusion_inverse.dat' using 1:3 title 'inverse'
quit
