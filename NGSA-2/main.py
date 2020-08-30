""" Non-dominated Sorting Genetic Algorithm 2 (NSGA 2)
    Refrence: Haris Ali Khan """
import sys
import math
import random
import matplotlib.pyplot as plt 


def function1(x):
    return -x**2

def function2(x):
    return -(x - 2)**2

# function to find index of list
def index_of(a, list):
    for i in range(0, len(list)):
        if (list[i] == a):
            return i 
    
    return -1

# function to sort by values
def sort_by_values(list1, values):
    sortedList = []
    while (len(sortedList) != len(list1)):
        if (index_of(min(values), values) in list1):
            sortedList.append(index_of(min(values), values))
        
        values[index_of(min(values), values)] = math.inf
    
    return sortedList

# function to carry out NGSA-II's fast non-dominated sort
def fast_non_dominated_sort(alpha, beta):
    S = [[] for i in range(0, len(alpha))]
    front = [[]]
    n = [0 for i in range(0, len(alpha))]
    rank = [0 for i in range(0, len(alpha))]
    for p in range(0, len(alpha)):
        S[p] = []
        n[p] = 0
        for q in range(0, len(alpha)):
            if (alpha[p] > alpha[q] and beta[p] > beta[q]) or (alpha[p] >= alpha[q] and beta[p] > beta[q]) or (alpha[p] > alpha[q] and beta[p] >= beta[q]):
                if q not in S[p]:
                    S[p].append(q)
            elif (alpha[q] > alpha[p] and beta[q] > beta[p]) or (alpha[q] >= alpha[p] and beta[q] > beta[p]) or (alpha[q] > alpha[p] and beta[q] >= beta[p]):
                n[p] = n[p] + 1
        
        if (n[p] == 0):
            rank[p] = 0
            if p not in front[0]:
                front[0].append(p)
    
    index = 0
    while (front[index] != []):
        Q = []
        for p in front[index]:
            for q in S[p]:
                n[q] = n[q] - 1
                if (n[q] == 0):
                    rank[q] = index + 1
                    if q not in Q:
                        Q.append(q)
        
        index += 1
        front.append(Q)
    
    del front[len(front) - 1]
    return front

# function to calculate crowding distance
def crowding_distance(alpha, beta, front):
    distance = [0 for i in range(0, len(front))]
    sorted1 = sort_by_values(front, alpha[:])
    sorted2 = sort_by_values(front, beta[:])
    distance[0] = sys.maxsize
    distance[len(front) - 1] = sys.maxsize
    for i in range(1, len(front) - 1):
        x = (alpha[sorted1[i + 1]] - beta[sorted1[i - 1]])
        y = (max(alpha) - min(alpha))
        distance[i] = distance[i] + x/y
    
    for i in range(1, len(front) - 1):
        x = (alpha[sorted2[i + 1]] - beta[sorted2[i - 1]])
        y = (max(beta) - min(beta))
        distance[i] = distance[i] + x/y
    
    return distance

# function to carry out the crossover
def crossover(alpha, beta, max, min):
    if (random.random() > 0.5):
        return mutation((alpha + beta)/2, max, min)
    else:
        return mutation((alpha - beta)/2, max, min)

# function to carry out the mutation operator
def mutation(result, max, min):
    if (random.random() < 1):
        result = min + (max - min) * random.random()
    
    return result

# main algorithm
def main(max, min, pop_size, max_gen):
    solution = [min + (max - min) * random.random() for i in range(0, pop_size)]
    itr = 0
    while (itr < max_gen):
        func1_value = [function1(solution[i]) for i in range(0, pop_size)]
        func2_value = [function2(solution[i]) for i in range(0, pop_size)]
        non_dominated_sorted_solution = fast_non_dominated_sort(func1_value[:], func2_value[:])

        print('The best fronts for epoch', itr, ' are:')
        for index in non_dominated_sorted_solution[0]:
            print(round(solution[index], 3), end=" ")
        print('\n')

        crowding_distance_values = []
        for i in range(0, len(non_dominated_sorted_solution)):
            crowding_distance_values.append(crowding_distance(func1_value[:], func2_value[:], non_dominated_sorted_solution[i][:]))
        
        # generating offsprings
        solution2 = solution[:]
        while (len(solution2) != 2 * pop_size):
            alpha = random.randint(0, pop_size - 1)
            beta = random.randint(0, pop_size - 1)
            solution2.append(crossover(solution[alpha], solution[beta], max, min))
        
        func1_values2 = [function1(solution2[i]) for i in range(0, 2 * pop_size)]
        func2_values2 = [function2(solution2[i]) for i in range(0, 2 * pop_size)]
        non_dominated_sorted_solution2 = fast_non_dominated_sort(func1_values2[:], func2_values2[:])

        crowding_distance_values2 = []
        for i in range(0, len(non_dominated_sorted_solution2)):
            crowding_distance_values2.append(crowding_distance(func1_values2[:], func2_values2[:], non_dominated_sorted_solution2[i][:]))
        
        new_solution = []
        for i in range(0, len(non_dominated_sorted_solution2)):
            tmp = [index_of(non_dominated_sorted_solution2[i][j], non_dominated_sorted_solution2[i]) for j in range(0, len(non_dominated_sorted_solution2[i]))]
            tmp_front = sort_by_values(tmp[:], crowding_distance_values2[i][:])
            front = [non_dominated_sorted_solution2[i][tmp_front[j]] for j in range(0, len(non_dominated_sorted_solution2[i]))]
            front.reverse()
            for index in front:
                new_solution.append(index)
                if (len(new_solution) == pop_size):
                    break
            
            if (len(new_solution) == pop_size):
                break
        
        solution = [solution2[i] for i in new_solution]
        itr += 1

    return func1_value, func2_value

# visualize the final front
def visualization(alpha, beta):
    Funct1 = [i * -1 for i in alpha]
    Funct2 = [j * -1 for j in beta]
    plt.style.use('dark_background')
    plt.xlabel('Function 1', fontsize=16)
    plt.ylabel('Function 2', fontsize=16)
    plt.scatter(Funct1, Funct2, color='r')
    plt.show()



obj1, obj2 = main(
    max =  55, 
    min = -55, 
    pop_size = 6, 
    max_gen = 600
    )

visualization(obj1, obj2)