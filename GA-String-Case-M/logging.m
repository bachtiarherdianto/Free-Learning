function logging(populasi, target, solusi, generasi, kombinasi)

    clc
    fprintf('Target : %s \n', target);
    fprintf('Hasil : %s \n', solusi.gen);
    fprintf('\n')
    fprintf('Total Kombinasi : %d \n', kombinasi);
    fprintf('Iterasi : %d \n', generasi);
    fprintf('\n')
    fprintf('Pilihan Solusi :\n')

    for i=1:length(populasi)
        fprintf('Solusi : %s ||', populasi(i).gen);
        fprintf('Kesesuaian : %f', populasi(i).fitness);
        fprintf('\n');
    end
end