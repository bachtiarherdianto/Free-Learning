import random
import sys
import copy
import numpy as np
import matplotlib.pyplot as plt
import math 
from matplotlib.font_manager import FontProperties


class Bee:
    def __init__(
        self, 
        lower, 
        upper, 
        fun, 
        funcon=None
        ):
        self.RANDOM(lower, upper)
        if not funcon:
            self.valid = True
        else:
            self.valid = funcon(self.vector)
        
        if (fun != None):
            self.value = fun(self.vector)
        else:
            self.value = sys.float_info.max
        
        self.FITNESS()
        self.counter = 0
    
    def RANDOM(self, lower, upper):
        self.vector = []
        for i in range(len(lower)):
            self.vector.append(
                lower[i] + random.random() * (upper[i] - lower[i])
                )

    def FITNESS(self):
        if (self.value >= 0):
            self.fitness = 1 / (1 + self.value)
        else:
            self.fitness = 1 + abs(self.value)

class Hive:
    def __init__(
        self, 
        lower,
        upper,
        fun = None,
        numb_bees = 30,
        max_itrs = 100,
        max_trials = None,
        selfun = None,
        seed = None,
        verbose = True,
        extra_params = None
        ):
        assert (len(upper) == len(lower))
        if (seed == None):
            self.seed = random.randint(0, 1000)
        else:
            self.seed = seed
        
        random.seed(self.seed)
        self.size = int((numb_bees + numb_bees % 2))    # compute number of employees
        self.dim = len(lower)
        self.max_itrs = max_itrs
        if (max_trials == None):
            self.max_trials = 0.6 * self.size * self.dim    # compute max_trials
        else:
            self.max_trials = max_trials
        
        self.selfun = selfun
        self.extra_params = extra_params
        self.evaluate = fun
        self.lower = lower
        self.upper = upper
        self.best = sys.float_info.max
        self.solution = None
        self.population = [Bee(lower, upper, fun) for i in range(self.size)]
        self.find_best()
        self.compute_probability()
        self.verbose = verbose
    
    def run(self):
        cost = {}
        cost["best"] = []
        cost["mean"] = []
        for itr in range(self.max_itrs):
            for index in range(self.size):
                self.send_employee(index)
            
            self.send_onlooker()
            self.send_scout()
            self.find_best()

            cost["best"].append(self.best)
            cost["mean"].append(sum([bee.value for bee in self.population])/self.size)

            if self.verbose:
                self.VERBOSE(itr, cost)
        
        return cost

    def find_best(self):
        values = [bee.value for bee in self.population]
        index = values.index(min(values))
        if (values[index] < self.best):
            self.best = values[index]
            self.solution = self.population[index].vector
    
    def compute_probability(self):
        values = [bee.fitness for bee in self.population]
        max_values = max(values)

        # computes probabilities the way Karaboga does in his classic ABC algorithm
        if (self.selfun == None):
            self.probas = [0.9 * v / max_values + 0.1 for v in values]
        else:
            if (self.extra_params != None):
                self.probas = self.selfun(list(values), **self.extra_params)
            else:
                self.probas = self.selfun(values)
        
        # returns intervals of probabilities
        return [sum(self.probas[:i + 1]) for i in range(self.size)]
    
    def send_employee(self, index):
        zombee = copy.deepcopy(self.population[index])
        d = random.randint(0, self.dim - 1)
        bee_ix = index
        while (bee_ix == index): 
            bee_ix = random.randint(0, self.size - 1)

        zombee.vector[d] = self.MUTATE(d, index, bee_ix)
        zombee.vector = self.CHECK(zombee.vector, dim = d)
        zombee.value = self.evaluate(zombee.vector)
        zombee.FITNESS()
        if (zombee.fitness > self.population[index].fitness):
            self.population[index] = copy.deepcopy(zombee)
            self.population[index].counter = 0
        else:
            self.population[index].counter += 1
    
    def send_onlooker(self):
        numb_onlokeers = 0
        beta = 0
        while (numb_onlokeers < self.size):
            phi = random.random()
            beta += phi * max(self.probas)
            beta %= max(self.probas)
            index = self.select(beta)
            self.send_employee(index)
            numb_onlokeers += 1
    
    def select(self, beta):
        probas = self.compute_probability()
        for index in range(self.size):
            if (beta < probas[index]):
                return index
    
    def send_scout(self):
        trials = [self.population[i].counter for i in range(self.size)]
        index = trials.index(max(trials))
        if (trials[index] > self.max_trials):
            self.population[index] = Bee(self.lower, self.upper, self.evaluate)
            self.send_employee(index)
    
    def MUTATE(self, dim, current_bee, other_bee):
        alpha = self.population[current_bee].vector[dim]
        beta = (random.random() - 0.5)
        gamma = self.population[other_bee].vector[dim]
        return alpha + beta * 2 * (alpha - gamma)
    
    def CHECK(self, vector, dim = None):
        if (dim == None):
            RANGE = range(self.dim)
        else:
            RANGE = [dim]
        
        for i in RANGE:
            if (vector[i] < self.lower[i]):
                vector[i] = self.lower[i]
            elif (vector[i] > self.upper[i]):
                vector[i] = self.upper[i]
        
        return vector
    
    def VERBOSE(self, itr, cost):
        msg = ">> Iter: {} || Best Error: {} || Mean Error: {}"
        print(msg.format(int(itr), cost["best"][itr], cost["mean"][itr]))

def ConvergencePlot(cost):
    font = FontProperties()
    font.set_size('larger')
    labels = ["Best Error", "Mean Error"]
    plt.figure(figsize=(12.5, 4))
    plt.plot(range(len(cost["best"])), cost["best"], label=labels[0])
    plt.scatter(range(len(cost["mean"])), cost["mean"], color='red', label=labels[1])
    plt.xlabel("Iteration")
    plt.ylabel("Error Value")
    plt.legend(loc="best", prop=font)
    plt.xlim([0, len(cost["mean"])])
    plt.grid()
    plt.show()

def ackley(x):
    alpha = 0.0
    beta = 0.0
    for i in x:
        alpha += i**2.0
        beta += math.cos(2.0 * math.pi * i)
    n = float(len(x))
    y = -20.0 * math.exp(-0.2 * math.sqrt(alpha/n)) - math.exp(beta/n) + 20 + math.e
    return y

def main(epochs):
    dimensions = int(10)
    model = Hive(
        lower= [-32] * dimensions,
        upper= [32] * dimensions,
        fun = ackley,
        numb_bees= 50,
        max_itrs= epochs
        )
    optimize = model.run()
    ConvergencePlot(optimize)
    print("Fitness Value: {0}".format(model.best))


main(100)