clear
clc

target = 'Vella';

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
besar_populasi = 6;
laju_mutasi = 0.1;
kombinasi = (126-32)^length(target);
[solusi, generasi] = simpleGA(target, besar_populasi, laju_mutasi, kombinasi);