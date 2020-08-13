function [solusi, generasi] = simpleGA(target, besar_populasi, laju_mutasi, kombinasi)
    populasi = create_population(target, besar_populasi);
    isLooping = true;
    generasi = 0;
    while isLooping
        % selection
        [parent1, parent2] = selection(populasi);

        % crossover
        [child1, child2] = crossover(parent1, parent2);

        % mutation  
        mutant1 = mutation(child1, laju_mutasi);
        mutant2 = mutation(child2, laju_mutasi);

        % menghitung fitnessnya mutant
        mutant1.fitness = calculated_fitness(mutant1.gen, target);
        mutant2.fitness = calculated_fitness(mutant2.gen, target);

        % regenarion
        children = [mutant1, mutant2];
        populasi = regeneration(children, populasi);
        generasi = generasi + 1;

        % termination
        [isLooping, solusi] = termination(populasi);
        logging(populasi, target, solusi, generasi, kombinasi);
    end
end