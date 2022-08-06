'''Taylor Polynomials
   Plot the function y = cos(x) along  with its Taylor Polynomials of degrees 2 and 4'''
import numpy as np
import matplotlib.pyplot as plt


x = np.linspace(-6, 6, 50)
y0 = np.cos(x)
plt.plot(x, y0, 'b', label=r'$ \mathcal{cos(x)}$')

y2 = 1 - x**2/2                             # plot degree 2 Taylor Polynomial
plt.plot(x, y2, 'r-.', label='Degree 2')

y4 = 1 - x**2/2 + x**4/24                   # plot degree 4 Taylor Polynomial
plt.plot(x, y4, 'g:', label='Degree 4')

plt.legend()
plt.grid(True, linestyle=':')
plt.ylim([-6, 6]), plt.xlim([-4, 4])        # -6 <= y <= 6 // -4 <= x <= 4
plt.title('Taylor Polynomials of ' + r'$ \mathcal{cos(x)}$' + ' at ' + r'$ \mathcal{x = 0}$')
plt.xlabel(r'$ \mathcal{x}$'), plt.ylabel(r'$ \mathcal{y}$')
plt.show()