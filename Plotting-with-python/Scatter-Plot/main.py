'''Scatter Plots'''
import numpy as np
import matplotlib.pyplot as plt


N = 2000                                                                            # set the number of dots in the plot
x, y = np.random.rand(N), np.random.rand(N)                                         # create random x and y coordinates sampled uniformly from [0, 1]
size, colors = 100*np.random.rand(N) + 20, np.random.rand(N, 4)                     # 'size' of each dots defined as random uniformly from [20, 120] and 'colors' of each dots defined as RGB-alpha (4-tuples) from random uniformly from [0, 1]
plt.figure(figsize=(12, 5))                                                         # create a figure of size 12 by 5 and create scatter plot
plt.scatter(x, y, c=colors, s=size)
plt.axis('off')   
plt.show()