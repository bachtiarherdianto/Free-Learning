'''Heart Curve at x = 16 sin^3(t) and y = 13 cos(t) - 5 cos(2t) - 2 cos(3t) - cos(4t)
   for 0 <= t <= 2phi'''
import numpy as np
import matplotlib.pyplot as plt 


t = np.linspace(0, 2*np.pi, 100)
x = 16 * np.sin(t)**3
y = 13 * np.cos(t) - 5 * np.cos(2*t) - 2 * np.cos(3*t) - np.cos(4*t)
plt.plot(x, y, c=(1, 0.2, 0.5), lw=2)     # with RGB tuple (red=1, green=0.2, blue=0.5) and 2pt line width
plt.title('Heart Curve')
plt.axis('equal')
plt.axis('off')
plt.show()