from pulp import *


# initialize optimization problem as maximization problem
prob = LpProblem('Maradona', LpMaximize)

# initialize variable
x1 = LpVariable('x1', lowBound=0)
x2 = LpVariable('x2', lowBound=0)

# define objective function
prob += 20*x1 + 30*x2

# define constraints
prob += 1*x1 + 2*x2 <= 100
prob += 2*x1 + 1*x1 <= 100

# display linear programming problem
print(prob)

# solve the problem
status = prob.solve()

# print out the results
print(LpStatus[status])
print(value(x1),
      value(x2),
      value(prob.objective))