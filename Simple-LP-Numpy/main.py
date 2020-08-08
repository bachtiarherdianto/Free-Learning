''' linear programming using numpy

    Y = A (dot) X

    Y1 = 2*X1 + 3*X2
    Y2 =   X1 + 2*X2

    23 = 2*X1 + 3*X2
    14 =   X1 + 2*X2

    ([23  14]) = ([2  3]  (dot)  ([X1  X2])
                  [1  2])   '''

import numpy as np
from fractions import Fraction as frac


A = np. array(
    [(2,3),
     (1,2)])

Y = np.array(
    [23,14])

print('Matrix A')
print (A)
print ('Matrix Y')
print (Y)

A_inv = np.linalg.inv(A)

X1 = np.dot(A_inv, Y)       # method 1
X2 = np.linalg.solve(A,Y)   # method 2

print ('Matrix Y from method 1 is:', X1)
print ('Matrix Y from method 2 is:', X2)