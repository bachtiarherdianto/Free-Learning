% fitness function
function fitness = calculated_fitness(gen, target)
    fitness = (sum(target == gen)/length(target))*100;
end