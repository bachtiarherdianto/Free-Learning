'''Plotting Eight Curve'''
import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 2*np.pi, 100)
x = np.sin(t)
y = np.sin(t)*np.cos(t)
plt.plot(x, y, c=(0.2, 0.4, 0.6), lw=2)
plt.title('Eight Curve')
plt.show()