'''Bar Plots'''
import numpy as np
import matplotlib.pyplot as plt

month = range(1, 13)
precipitation = [98.8, 128.8, 206.0,
                 138.5, 102.2, 46.4,
                 1.8, 5.0, 29.4,
                 114.8, 197.0, 170.6]
plt.bar(month, precipitation)
plt.xticks(month), plt.yticks(range(0, 300, 50))
plt.grid(True, alpha=0.5, linestyle='--')
plt.title('Precipitation in Magetan, 2016'), plt.ylabel('Total Precipitation (mm)'), plt.xlabel('Month')
plt.show()