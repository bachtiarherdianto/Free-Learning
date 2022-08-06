'''Rastrigin Function
   The Rastrigin Function is often used when exploring numerical optimization
   because the function has one true minimum value at
   x = 0
   y = 0
   but many local minima nearby'''
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

x = np.linspace(-5.12, 5.12, 100)
y = np.linspace(-5.12, 5.12, 100)
x, y = np.meshgrid(x, y)

z = (
        x**2 - 10*np.cos(2*np.pi*x)
     ) + (
        y**2 - 10*np.cos(2*np.pi*y)
          ) + 20

pict = plt.figure()
ax = pict.gca(projection='3d')
ax.plot_surface(x, y, z, rstride=1, cstride=1, cmap=cm.nipy_spectral, linewidth=0.08, antialiased=True)
# plt.savefig('graph_trial.png')
plt.show()