'''Subplots - Sawtooth Wave'''
import numpy as np
import matplotlib.pyplot as plt 

t, fN = np.linspace(0, 4, 200), 1/2
for N in [1, 2, 3, 4]:
    fN = fN - (-1)**N * np.sin(2*N*np.pi*t) / (N*np.pi)
    plt.subplot(2, 2, N)
    plt.plot(t, fN)
    plt.title('N = {}'.format(N))
plt.tight_layout()
plt.show()