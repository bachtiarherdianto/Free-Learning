'''Histogram
   from function y = (1/sqrt(2*phi)^(exp^((-x^2)/2))'''
import numpy as np
import matplotlib.pyplot as plt

samples = np.random.randn(10000)
plt.hist(samples, bins=20, density=True, alpha=0.5, color=(0.3, 0.8, 0.1))
plt.title('Random Samples - Normal Distribution'), plt.ylabel(r'$ \mathcal{Frequency}$')
x = np.linspace(-4, 4, 100)
y = 1/(2*np.pi)**0.5 * np.exp(-x**2/2)
plt.plot(x, y, 'b', alpha=0.8)
plt.show()